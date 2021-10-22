#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    // the size of temp = 10 and value = 0 (by default) in each position
    vector<int> temp(10);
    for(auto i: temp){
        cout<<i<<" ";
    }
    cout<<endl;
    // the size of temp = 10 and value = 1 in each position
    vector<int> temp1(10, 1);
    for(auto i: temp1){
        cout<<i<<" ";
    }
    cout<<endl;
    // putting the value of temp1 in another vector
    vector<int> container(10, -1);
    // can also do write this : vector<int> container(10);
    for(int i=0; i<10; i++){
        container[i] = temp1[i];
    }
    for (auto i : container)
    {
        cout << i << " ";
    }
    return 0;
}