#include <iostream>
using namespace std;

class A
{
public:
    void funcA()
    {
        cout << "funcA" << endl;
    }
};

class B
{
protected:
    void funcB(){
        cout<<"funcB"<<endl;
    }
};

class C: public B, public A{

};
int main()
{
    C obj;
    obj.funcA();
    // obj.funcB(); -> Will give error
    return 0;
}