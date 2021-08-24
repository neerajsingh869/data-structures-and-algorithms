#include <iostream>
using namespace std;

void maxofThree(int a, int b, int c)
{
    if (a > b)
    {
        if (c > a)
        {
            cout << "Max: " << c << endl;
        }
        else
        {
            cout << "Max: " << a << endl;
        }
    }
    else
    {
        if (c > b)
        {
            cout << "Max: " << c << endl;
        }
        else
        {
            cout << "Max: " << b << endl;
        }
    }
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    // function to print max. of three values
    maxofThree(a, b, c);
    return 0;
}