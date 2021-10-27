#include<iostream>
using namespace std;

class complex{
private:
    int real, imag;
public:
    complex(int r, int i){
        real = r;
        imag = i;
    }

    // Since I have made parameterised constructor, I have to manually make the default one.
    complex(){

    }

    // Operator overloading for finding the sum of two complex numbers
    complex operator + (complex &obj){
        complex result;
        result.real = real + obj.real;
        result.imag = imag + obj.imag;
        return result;
    }

    // Displaying the results
    void display(){
        cout<<real<<" + i"<<imag<<endl;
    }

};

int main(){
    complex c1(10, 20);
    complex c2(15, 25);
    complex c3 = c1+c2;
    c3.display();
    return 0;
}