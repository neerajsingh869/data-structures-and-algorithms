#include<iostream>
using namespace std;
// call by reference
void swap(int &i, int &j)
{
    int tmp = i;
    i = j;
    j = tmp;
}
int main()
{
    int x, y;
    x = 5;
    y = 10;
    swap(x, y);
    cout<<x<<" "<<y<<endl;
}