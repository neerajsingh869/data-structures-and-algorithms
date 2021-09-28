#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int found = false;
    // Position of top right element (Can also take bottom left element)
    int r = 0, c = m-1;
    while(r<n && c>=0){
        if(arr[r][c] == k){
            cout<<r<<" "<<c<<endl;
            found = true;
            break;
        }
        else if(arr[r][c] > k){
            c--;
        }
        else{
            r++;
        }
    }
    if(found){
        cout<<"Element found.";
    }
    else{
        cout<<"Element not found.";
    }
    return 0;
}