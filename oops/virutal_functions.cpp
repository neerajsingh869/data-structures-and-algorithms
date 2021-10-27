#include<iostream>
using namespace std;

class base{
public:
    void print(){
        cout<<"Base class's Print"<<endl;
    }
    // virtual is the keyword used to decide which function to call during run time.
    virtual void display(){
        cout<<"Base class's Display"<<endl;
    }
};

class derived : public base{
public:
    void print()
    {
        cout << "Derived class's Print" << endl;
    }
    void display()
    {
        cout << "Derived class's Display" << endl;
    }
};

int main(){
    derived d;
    // It will do the normal thing.
    d.print();
    d.display();
    base *ptr;
    ptr = &d;
    // It will behave abnormally.
    ptr -> print();
    ptr -> display();
    return 0;
}