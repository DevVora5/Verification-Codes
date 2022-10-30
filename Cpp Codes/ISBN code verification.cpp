#include <iostream>
using namespace std;

bool isValidISBN(string isbn)
{
    if (isbn.length() != 10)
        return false;

    int sum = 0;
    for (int i = 0; i < 9; i++)
    {
        int digit = isbn[i] - '0';
        if (digit < 0 || digit > 9)
            return false;
        sum += (digit * (10 - i));
    }

    char end = isbn[9];
    if (end != 'X' && (end < '0' || end > '9'))
        return false;

    if (end == 'X')
        sum += 10;
    else
        sum += (end - '0');

    return (sum % 11 == 0);
}

int main()
{
    string isbn;
    cout << "Enter ISBN Number:";
    cin >> isbn;

    if (isValidISBN(isbn))
        cout << "Valid";
    else
        cout << "Invalid";
    return 0;
}