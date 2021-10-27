#include <iostream>
using namespace std;

class student
{
    // By default, everything inside class is private
public:
    string name;
    int age;
    char gender;

    // Default constructor
    student(){
        cout<<"Default constructor"<<endl;
    }

    // Parameterised constructor
    student(string s, int a, char g){
        cout<<"Parameterised constructor"<<endl;
        name = s;
        age = a;
        gender = g;
    }

    // Copy constructor
    student(student &a){
        cout<<"Copy constructor"<<endl;
        name = a.name;
        age = a.age;
        gender = a.gender;
    }

    // Destructor
    ~student(){
        cout<<"Destructor called"<<endl;
    }

    // Making method for printing out the object details
    void printInfo()
    {
        cout << "Name: ";
        cout << name << endl;
        cout << "Age: ";
        cout << age << endl;
        cout << "Gender: ";
        cout << gender << endl;
    }
};

int main()
{   
    // Calling parameterised constructor
    student a("Neeraj", 21, 'M');
    // Calling default constructor
    student b;
    // Calling copy constructor
    student c(a);
    c.printInfo();
    return 0;
}