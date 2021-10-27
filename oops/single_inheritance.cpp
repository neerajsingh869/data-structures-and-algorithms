#include<iostream>
using namespace std;

class base{
public:
    void func(){
        cout<<"Inherited"<<endl;
    }
};

class derived : public base{

};

int main(){
    derived obj;
    obj.func();
    return 0;
}