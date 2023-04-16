#include <iostream>
#include "regToNFA.h"

using namespace std;

int main()
{
    regToNFAConvertor *regToNFA = new regToNFAConvertor();
    string reg = "a+b*.c+d";
    NFAGraph *nfa = regToNFA->regToNFA(reg);
    cout << nfa->isValidString("abd") << endl;
    cout << nfa->isValidString("acd") << endl;
    cout << nfa->isValidString("ac") << endl;
    cout << nfa->isValidString("bc") << endl;
    cout << nfa->isValidString("bbc") << endl;
}