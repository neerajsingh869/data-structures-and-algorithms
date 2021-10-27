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

class B : public A
{
public:
    void funcB()
    {
        cout << "funcB" << endl;
    }
};

class C : public B
{
};
int main()
{
    C obj;
    obj.funcA();
    obj.funcB();
    return 0;
}