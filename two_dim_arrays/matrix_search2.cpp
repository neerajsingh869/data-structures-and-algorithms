#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    cin>>n>>m>>k;
    int arr[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    // A little better algorithm than matrix_search1
    int found = false;
    for(int i=0; i<n; i++){
        int col_start = 0;
        int col_end = m-1;    
        while(col_end - col_start >= 0){
            int mid_col = (col_start + col_end) / 2;
            if(arr[i][mid_col] == k){
                cout<<i<<" "<<mid_col<<endl;
                found = true;
                break;
            }
            else if(arr[i][mid_col] > k){
                col_end = mid_col -1;
            }
            else{
                col_start = mid_col + 1;
            }
        }
        if(found){
            cout<<"Element found." << endl;
            break;
        }
    }
    if(not(found)){
        cout<<"Element not found."<<endl;
    }
    return 0;
}