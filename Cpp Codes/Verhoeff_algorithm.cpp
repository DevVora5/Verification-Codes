#include <iostream>
using namespace std;

int isValidAadhar(long aadhar_no)
{
    int d[10][10] = {
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 2, 3, 4, 0, 6, 7, 8, 9, 5},
        {2, 3, 4, 0, 1, 7, 8, 9, 5, 6},
        {3, 4, 0, 1, 2, 8, 9, 5, 6, 7},
        {4, 0, 1, 2, 3, 9, 5, 6, 7, 8},
        {5, 9, 8, 7, 6, 0, 4, 3, 2, 1},
        {6, 5, 9, 8, 7, 1, 0, 4, 3, 2},
        {7, 6, 5, 9, 8, 2, 1, 0, 4, 3},
        {8, 7, 6, 5, 9, 3, 2, 1, 0, 4},
        {9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
    };

    int p[8][10] = {
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 5, 7, 6, 2, 8, 3, 0, 9, 4},
        {5, 8, 0, 3, 7, 9, 6, 1, 4, 2},
        {8, 9, 1, 6, 0, 4, 3, 5, 2, 7},
        {9, 4, 5, 3, 1, 2, 6, 8, 7, 0},
        {4, 2, 8, 6, 5, 7, 3, 9, 0, 1},
        {2, 7, 9, 3, 8, 0, 6, 4, 1, 5},
        {7, 0, 4, 6, 9, 1, 3, 2, 5, 8},
    };

    int inv[10] = {0,
                   4,
                   3,
                   2,
                   1,
                   5,
                   6,
                   7,
                   8,
                   9};

    string aadhar_str = to_string(aadhar_no);
    if (aadhar_str.length() != 12)
        return false;
    int c = 0, digit = 0, p_i_ni = 0;
    for (int i = 0; i < 12; i++)
    {
        digit = aadhar_no % 10;
        aadhar_no = aadhar_no / 10;
        p_i_ni = p[i % 8][digit];
        c = d[c][p_i_ni];
    }

    if (c == 0)
        return true;
    else
        return false;
}
int main()
{

    long code;
    cout << "Enter Aadhaar Number to be verified:";
    cin >> code;
    if (isValidAadhar(code))
        cout << "Valid" << endl;
    else
        cout << "Invalid" << endl;
    return 0;
}
