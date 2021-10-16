#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    
}

int main()
{
    int a = 2;
    int b = 4;
    // Passed the address of the variables to the swap function
    swap(&a, &b);
    cout << a << " " << b;
    return 0;
}