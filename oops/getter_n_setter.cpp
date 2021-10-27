#include <iostream>
using namespace std;

class student
{
    string name;
public:
    int age;
    char gender;

    // Making method to access private members from outside the class
    void setName(string s){
        name = s;
    }

    // getter method
    void getName(){
        cout<<name<<endl;
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
    // Making multiple objects of same class
    student arr[2];
    for (int i = 0; i < 2; i++)
    {    
        string s;
        cout << "Name: ";
        cin >> s;
        arr[i].setName(s);
        cout << "Age: ";
        cin >> arr[i].age;
        cout << "Gender: ";
        cin >> arr[i].gender;
    }
    for (int i = 0; i < 2; i++)
    {
        arr[i].printInfo();
    }
    return 0;
}