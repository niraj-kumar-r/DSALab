#include "regToNFA.h"
#include <iostream>
#include <stack>

using namespace std;

NFAGraphState::NFAGraphState()
{
    this->edgeTransitions["@"].insert(this);
    this->isAccepting = false;
}

NFAGraphState::NFAGraphState(bool isAccepting)
{
    this->edgeTransitions["@"].insert(this);
    this->isAccepting = isAccepting;
}

unordered_set<NFAGraphState *> NFAGraph::transitionFunction(NFAGraphState *currentState, std::string input)
{
    return currentState->edgeTransitions[input];
}

unordered_set<NFAGraphState *> NFAGraph::epsilonClosure(NFAGraphState *currentState)
{
    return currentState->edgeTransitions["@"];
}

bool NFAGraph::isValidString(std::string input)
{
    unordered_set<NFAGraphState *> currentStates = epsilonClosure(startState);
    for (int i = 0; i < input.length(); i++)
    {
        unordered_set<NFAGraphState *> nextStates;
        for (NFAGraphState *state : currentStates)
        {
            unordered_set<NFAGraphState *> temp = transitionFunction(state, input.substr(i, 1));
            nextStates.insert(temp.begin(), temp.end());
        }
        currentStates = nextStates;
    }
    for (NFAGraphState *state : currentStates)
    {
        if (state->isAccepting)
        {
            return true;
        }
    }
    return false;
}

NFAGraph *regToNFAConvertor::getConcat(NFAGraph *nfa1, NFAGraph *nfa2)
{
    NFAGraph *nfa = new NFAGraph();
    nfa->alphabet = nfa1->alphabet;
    nfa->alphabet.insert(nfa2->alphabet.begin(), nfa2->alphabet.end());
    nfa->States = nfa1->States;
    nfa->States.insert(nfa2->States.begin(), nfa2->States.end());
    nfa->startState = nfa1->startState;
    nfa->acceptingStates = nfa2->acceptingStates;
    for (NFAGraphState *state : nfa1->acceptingStates)
    {
        state->edgeTransitions["@"].insert(nfa2->startState);
    }
    delete nfa1;
    delete nfa2;
    return nfa;
}

NFAGraph *regToNFAConvertor::getUnion(NFAGraph *nfa1, NFAGraph *nfa2)
{
    NFAGraph *nfa = new NFAGraph();
    nfa->alphabet = nfa1->alphabet;
    nfa->alphabet.insert(nfa2->alphabet.begin(), nfa2->alphabet.end());
    nfa->States = nfa1->States;
    nfa->States.insert(nfa2->States.begin(), nfa2->States.end());
    nfa->startState = new NFAGraphState();
    nfa->States.insert(nfa->startState);
    nfa->startState->edgeTransitions["@"].insert(nfa1->startState);
    nfa->startState->edgeTransitions["@"].insert(nfa2->startState);
    NFAGraphState *newState = new NFAGraphState(true);
    nfa->States.insert(newState);
    nfa->acceptingStates.insert(newState);
    for (NFAGraphState *state : nfa1->acceptingStates)
    {
        state->edgeTransitions["@"].insert(newState);
    }
    for (NFAGraphState *state : nfa2->acceptingStates)
    {
        state->edgeTransitions["@"].insert(newState);
    }
    delete nfa1;
    delete nfa2;
    return nfa;
}

NFAGraph *regToNFAConvertor::getStar(NFAGraph *nfa)
{
    NFAGraph *newNFA = new NFAGraph();
    newNFA->alphabet = nfa->alphabet;
    newNFA->States = nfa->States;
    newNFA->startState = new NFAGraphState(true);
    newNFA->States.insert(newNFA->startState);
    newNFA->acceptingStates.insert(newNFA->startState);
    newNFA->startState->edgeTransitions["@"].insert(nfa->startState);
    // newNFA->startState->edgeTransitions["@"].insert(newNFA->startState);
    NFAGraphState *newState = new NFAGraphState(true);
    newNFA->States.insert(newState);
    newNFA->acceptingStates.insert(newState);
    for (NFAGraphState *state : nfa->acceptingStates)
    {
        state->edgeTransitions["@"].insert(nfa->startState);
        state->edgeTransitions["@"].insert(newState);
    }
    delete nfa;
    return newNFA;
}

// regex can also have brackets
// for eg. ab+(a.b)*a is a valid regex
// (a+b)*.a is also a valid regex
NFAGraph *regToNFAConvertor::regToNFA(string reg)
{
    reg = "(" + reg + ")";
}