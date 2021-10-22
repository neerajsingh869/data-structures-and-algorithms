#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout<< a[i] << " ";
    }
    cout<<"\n"<<a.size();
    cout << "\n"<< a.max_size();
    return 0;
}