#include <iostream>
using namespace std;

int digitSum(long num)
{
    int sum = 0, digit = 0;
    for (int i = 0; i < 16; i++)
    {
        digit = num % 10;
        num = num / 10;
        if (i % 2 == 0)
            sum += digit;
        else
        {
            if (digit * 2 > 8)
                sum += ((digit * 2) % 10) + ((digit * 2) / 10);
            else
                sum += (digit * 2);
        }
    }
    return sum;
}

int checkCard(long CardNo)
{
    string Num = to_string(CardNo);
    if (Num.length() != 16)
        return false;
    if (digitSum(CardNo) % 10 == 0)
        return true;
    else
    {
        cout << digitSum(CardNo) << endl;
        return false;
    }
}

int main()
{
    long code;
    cout << "Enter Credit card code:";
    cin >> code;
    if (checkCard(code))
    {
        cout << "This is a Valid Card.";
    }
    else
    {
        cout << "This is an Invalid Card.";
    }
    return 0;
}