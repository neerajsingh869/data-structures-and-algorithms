#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    // Initial difference
    int diff1;
    int num1, num2;
    cin >> num1 >> num2;
    diff1 = num2 - num1;
    // Storing temporary difference
    int diff2;
    for (int i = 3; i <= n; i++)
    {
        int temp;
        cin >> temp;
        num1 = num2;
        num2 = temp;
        // difference between next two numbers
        diff2 = num2 - num1;
        /* if diff2 is not same as initail difference,
        then it is not ap.*/
        if (diff2 != diff1)
        {
            cout << "false" << endl;
            break;
        }
    }
    /* At the end, if the last difference is same as that
    of the initial difference, then the series is AP*/
    if (diff2 == diff1)
    {
        cout << "true" << endl;
    }
    return 0;
}