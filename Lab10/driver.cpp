#include <iostream>
#include "regToNFA.h"

using namespace std;

int main()
{
    regToNFAConvertor *regToNFA = new regToNFAConvertor();
    string reg;
    NFAGraph *nfa = nullptr;
    string str;
    int choice;
    bool result;
    while (true)
    {
        cout << endl;
        cout << "Hello, Welcome to the NFA simulator\n"
             << endl;
        cout << "Present Regex: " << reg << endl;
        cout << "Choices: " << endl;
        cout << "1. Enter a regular expression" << endl;
        cout << "2. Check if a string is valid" << endl;
        cout << "3. Get shortest string\n";
        cout << "4. Exit\n"
             << endl;
        cout << "Enter your choice: ";
        cout << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the regular expression: ";
            cin >> reg;
            nfa = regToNFA->regToNFA(reg);
            break;
        case 2:
            if (nfa == nullptr)
            {
                cout << "Please enter a regular expression first" << endl;
                break;
            }
            cout << "Enter the string: ";
            cin >> str;
            result = nfa->isValidString(str);
            if (result)
            {
                cout << "Accepted :)" << endl;
            }
            else
            {
                cout << "Rejected :(" << endl;
            }
            break;
        case 3:
            if (nfa == nullptr)
            {
                cout << "Please enter a regular expression first" << endl;
                break;
            }
            cout << "Shortest string: " << nfa->shortestValidString() << endl;
            break;

        case 4:
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }
}