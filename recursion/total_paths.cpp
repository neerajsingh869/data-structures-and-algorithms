#include<iostream>
using namespace std;

int total_path(int s, int e){
    if(s==e){
        return 1;
    }
    if(s>e){
        return 0;
    }
    int count = 0;
    for(int i = 1; i<6; i++){
        count += total_path(s+i, e); 
    }
    return count;
}

int main(){
    cout<<total_path(0, 3);
    return 0;
}