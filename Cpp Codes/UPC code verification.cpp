#include <iostream>
using namespace std;

int isValidupc(long upc)
{
    int sum = 0, digit = 0;
    long num = upc;

    for (int i = 0; i < 13; i++)
    {
        digit = num % 10;
        if (i % 2 == 0)
            sum += digit * 1;
        else
            sum += digit * 3;
        num = num / 10;
    }
    if (sum % 10 == upc % 10)
        return true;
    else
        return false;
}
int main()
{
    long code;
    cout << "Enter the upc code to be verified: ";
    cin >> code;
    if (isValidupc(code))
        cout << "Valid";
    else
        cout << "Invalid";
    return 0;
}