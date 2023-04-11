#ifndef REG_TO_NFA_H
#define REG_TO_NFA_H

#include <string>
#include <unordered_map>
#include <unordered_set>

class NFAGraphState
{
    std::unordered_multimap<std::string, NFAGraphState *> edgeTransitions;
    bool isAccepting;
};

class NFAGraph
{
    std::unordered_set<NFAGraphState *> States;
    std::unordered_set<std::string> alphabet;
    NFAGraphState *startState;
    std::unordered_set<NFAGraphState *> acceptingStates;
    std::unordered_set<NFAGraphState *> transitionFunction(NFAGraphState *currentState, std::string input);
    std::unordered_set<NFAGraphState *> epsilonClosure(NFAGraphState *currentState);
    bool isValidString(std::string);
};

class regToNFAConvertor
{
public:
    NFAGraph regToNFA(std::string reg);
};

#endif