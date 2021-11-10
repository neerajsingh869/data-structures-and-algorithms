#include<iostream>
using namespace std;

int max_value(int val[], int wei[], int n, int W){
    if (W <= 0 || n == 0)
    {
        return 0;
    }
    if(W-wei[0] < 0){
        return max_value(val + 1, wei + 1, n - 1, W);
    }
    int ifSelected = val[0] + max_value(val+1, wei+1, n-1, W-wei[0]);
    int ifNotSelected = max_value(val + 1, wei + 1, n-1, W);
    return max(ifSelected, ifNotSelected);
}

int main(){
    int n, W;
    cin>>n>>W;
    int val[n], wei[n];
    for(int i = 0; i < n; i++){
        cin>>val[i];
    }
    for(int i = 0; i < n; i++){
        cin>>wei[i];
    }
    cout<<max_value(val, wei, n, W);
    return 0;
}