#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    cin>>n>>m>>k;
    int arr[n][m];
    for(int i = 0; i< n; i++){
        for(int j = 0; j< m; j++){
            cin>>arr[i][j];
        }
    }

    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == k)
            {
                cout << "Element "<<k<<" is Found "<< " at " << i << "th row and " << j << "th column" << endl;
                flag = true;
                break;
            }
        }
        if(flag){
            break;
        }
    }
    if(not(flag)){
        cout<<"Element not found."<<endl;
    }
    return 0;
}