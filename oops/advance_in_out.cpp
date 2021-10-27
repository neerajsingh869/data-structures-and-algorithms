#include <iostream>
using namespace std;

class student
{
    // By default, everything inside class is private
    public:
    string name;
    int age;
    char gender;

    // Making method for printing out the object details
    void printInfo(){
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
    for(int i = 0; i < 2; i++){
        cout<<"Name: ";
        cin>>arr[i].name;
        cout<<"Age: ";
        cin>>arr[i].age;
        cout<<"Gender: ";
        cin>>arr[i].gender;
    }
    
    // Method 1 of printing the objects and their values
    // for(int i = 0; i < 2; i++){
    //     cout << "Name: ";
    //     cout << arr[i].name << endl;
    //     cout << "Age: ";
    //     cout << arr[i].age << endl;
    //     cout << "Gender: ";
    //     cout << arr[i].gender << endl;
    // }

    // Method 2 of printing the objects and their values (By calling method of class)
    for(int i = 0; i < 2; i++){
        arr[i].printInfo();
    }
    return 0;
}