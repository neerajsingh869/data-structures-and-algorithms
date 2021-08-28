#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int maxim = INT_MIN;
    for (int i = 0; i < n; i++)
    {           
        maxim = max(arr[i], maxim);
        cout << "Max till " << i << ":" << maxim << endl;
    }
    return 0;
}