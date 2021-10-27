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
    student()
    {
        
    }

    // Parameterised constructor
    student(string s, int a, char g)
    {
        name = s;
        age = a;
        gender = g;
    }

    // Copy constructor
    student(student &a)
    {
        name = a.name;
        age = a.age;
        gender = a.gender;
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

    // Operator overloading -> We can define how a operator should function
    // operator is keyword
    bool operator == (student &a){
        if(name == a.name && age == a.age && gender == a.gender){
            return true;
        }
        else{
            return false;
        }
    }
};

int main()
{
    // Calling parameterised constructor
    student a("Neeraj", 21, 'M');
    student b("Amul", 22, 'M');
    // Calling copy constructor
    student c(a);
    // or student c = a;

    if(b == a){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Different"<<endl;
    }
    return 0;
}