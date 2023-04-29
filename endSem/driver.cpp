#include <iostream>
#include "regToNFA.h"

using namespace std;

int main()
{
    regToNFAConvertor *regToNFA = new regToNFAConvertor();
    string reg;
    cout << "Enter regex : ";
    cin >> reg;
    cout << endl;
    NFAGraph *nfa = regToNFA->regToNFA(reg);
    bool hasStar = false;
    for (int i = 0, n = reg.size(); i < n; i++)
    {
        if (reg[i] == '*')
        {
            hasStar = true;
            break;
        }
    }
    if (hasStar)
    {
        cout << "Language is Infinite" << endl;
    }
    else
    {
        cout << "Language is Finite" << endl;
    }
    string str;
    cout << "Enter the string : ";
    cin >> str;
    cout << endl;

    cout << nfa->shortestStringLongestPrefix(str) << endl;
}