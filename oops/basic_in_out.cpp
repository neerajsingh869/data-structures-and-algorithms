#include<iostream>
using namespace std;

class student{
    // By default, everything inside class is private
    public:
    string name;
    int age;
    char gender;
};

int main(){
    // Making a single object/instance of a class
    student a;
    a.name = "Neeraj";
    a.age = 21;
    a.gender = 'M';
    cout<<"Name: ";
    cout<<a.name<<endl;
    cout << "Age: ";
    cout << a.age << endl;
    cout << "Gender: ";
    cout << a.gender << endl;
    return 0;
    // What if we have to make many instances of a class -> see next code example.
}