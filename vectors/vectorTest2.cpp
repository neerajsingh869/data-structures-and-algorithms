#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    // If you don't put &, then the ouput for will not work properly.
    for (auto &i: a)
    {
        cin >> i;
    }
    for (auto i : a)
    {
        cout << i << " ";
    }
    return 0;
}