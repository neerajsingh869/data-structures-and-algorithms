#include<iostream>
using namespace std;

class funcOverload{
public:
    void fun(){
        cout<<"Function with no arguments"<<endl;
    }
    void fun(int a){
        cout<<"Function with int argument"<<endl;
    }
    void fun(string s, int b){
        cout<<"Function with string and int arguments"<<endl;
    }
};

int main(){
    funcOverload obj;
    obj.fun();
    obj.fun(10);
    obj.fun("Himy friend", 20);
    return 0;
}