#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    // First method
    vector<int> a(n);
    vector<int>::iterator it;
    for (it = a.begin(); it != a.end(); it++)
    {
        cout << *it << " ";
    }
    cout<<endl;
    // Second method
    vector<int> a1(n);
    for(vector<int>::iterator it = a1.begin(); it != a1.end(); it++){
        cout<<*it <<" ";
    }
    cout<<endl;
    // Third method
    vector<int> a2(n);
    for (auto it = a2.begin(); it != a2.end(); it++)
    {
        cout << *it << " ";
    }
    return 0;
}