#include<iostream>
using namespace std;

bool pythagoras(int n1, int n2, int n3){
    bool c = (n1 * n1 + n2 * n2 == n3 * n3) || (n2 * n2 + n3 * n3 == n1 * n1) || (n3 * n3 + n1 * n1 == n2 * n2);
    return c;
}

int main(){
    int x, y, z;
    cin>>x>>y>>z;
    if(pythagoras(x, y, z)){
        cout<<"Pythogaras triplet." <<endl;
    }
    else{
        cout<<"Not pythagoras triplet." <<endl;
    }
    return 0;
}