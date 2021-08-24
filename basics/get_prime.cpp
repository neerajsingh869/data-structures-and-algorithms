#include <iostream>
using namespace std;

int main(){
    int a,b;
    cout<<"Enter two numbers:"<<endl;
    cin>>a>>b;
    for(int i = a+1; i<b; i++){
        int j;
        for(j=2; j<i; j++){
            if(i%j == 0){
                break;
            }
        }
        if(j == i){
            cout<<i<<endl;
        }
    }
    return 0;
}