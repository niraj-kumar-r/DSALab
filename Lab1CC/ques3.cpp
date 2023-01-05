#include <iostream>

using namespace std;

int main(void)
{
    int number = 0, sum = 0;
    char flag;
    while (true)
    {
        cout << "Enter a Number : ";
        cin >> number;

        sum += number;

        cout << "Do you want to continue? [y/n] [By default takes n] : ";
        cin >> flag;
        cout << endl;

        if (flag == 'y' or flag == 'Y')
        {
            continue;
        }
        else
        {
            cout << "The sum is " << sum << endl;
            break;
        }
    }
}