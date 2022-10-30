#include <iostream>
using namespace std;

int digitSum(long num)
{
    int digit = 0, sum = 0;
    num = num / 10;
    for (int i = 0; i < 10; i++)
    {
        digit = num % 10;
        num = num / 10;
        sum += digit;
    }
    return sum;
}

int isValidUSPMO(long uspmo)
{
    string uspmo_str = to_string(uspmo);
    if (uspmo_str.length() != 11)
        return false;
    if (digitSum(uspmo) % 9 == uspmo % 10)
        return true;
    else
        return false;
}

int errorRectifier(long num)
{
    cout << "Possible Valid Code can be (Only if the Last Digit is entered incorrectly): "
         << (num / 10) * 10 + (digitSum(num) % 9) << endl;
    return 0;
}
int main()
{
    long code;
    cout << "Enter a US Postal Money Order Code: ";
    cin >> code;
    if (isValidUSPMO(code))
        cout << "Valid" << endl;
    else
    {
        cout << "Invalid" << endl;
        errorRectifier(code);
    }
    return 0;
}