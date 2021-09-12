#include<iostream>
#include<string>
using namespace std;

int main(){
    string str = "abdddcccm";
    char comp[100];
    comp[0] = str[0];
    int idx = 1;
    for(int i = 1; i < str.size(); i++){
        if(str[i] != str[i-1]){
            comp[idx] = str[i];
            idx++;
        }
    }
    cout<<comp<<endl;
    return 0;
}