#include<iostream>
using namespace std;

class A{
public:
    int a;
    void funcA(){
        cout<<"FuncA"<<endl;
    }
private:
    int b;
    void funcB()
    {
        cout << "FuncB" << endl;
    }
protected:
    int c;
    void funcC()
    {
        cout << "FuncC" << endl;
    }
};

int main(){
    A obj;
    obj.a = 2;
    obj.funcA();
    // obj.funcB(); -> Get error
    return 0;
}