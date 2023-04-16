#include <iostream>
#include "regToNFA.h"

using namespace std;

int main()
{
    regToNFAConvertor *regToNFA = new regToNFAConvertor();
    string reg = "a.b*+a*.(a*.b+a*)*.b+b*.a";
    cout << regToNFA->regex_to_prefix(reg) << endl;
}