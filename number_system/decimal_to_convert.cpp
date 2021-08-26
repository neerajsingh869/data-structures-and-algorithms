#include<bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;

int dec_to_bin(int num)
{
    int bin = 0;
    int i=0;
    // i represent the highest power that divides the decimal number.
    while (pow(2, i)<=num)
        i++;
    for (int j = i-1; j >= 0; j--)
    {
        int quo = num / pow(2, j);
        bin = bin * 10 + quo;
        num -= quo * pow(2, j);
    }
    return bin;
}

int dec_to_oct(int num)
{
    int oct = 0;
    int i = 0;
    // i represent the highest power that divides the decimal number.
    while (pow(8, i) <= num)
        i++;
    for (int j = i-1; j >= 0; j--)
    {
        int quo = num / pow(8, j);
        oct = oct * 10 + quo;
        num -= quo * pow(8, j);
    }
    return oct;
}

string dec_to_hex(int num)
{   
    string hex = "";
    int i = 0;
    // i represent the highest power that divides the decimal number.
    while (pow(16, i) <= num)
        i++;
    for (int j = i-1; j >= 0; j--){
        int quo = num / pow(16, j);
        num -= quo * pow(16, j);
        if (quo <= 9)
        {
            hex = hex + to_string(quo);
        }
        else
        {   
            char c = 'A' + quo - 10;
            hex.push_back(c);
        }
    }
    return hex;
    // string hex = "";
    // int x = 1;
    // while(x<=num)
    //     x*=16;
    // x /= 16;

    // while(x>0){
    //     int quo = num / x;
    //     num -= quo * x;
    //     x/=16;
    //     if(quo <= 9)
    //     {
    //         hex = hex + to_string(quo);
    //     }
    //     else
    //     {
    //         char c = 'A' + quo - 10;
    //         hex.push_back(c);
    //     }
    // }
    // return hex;
}

int main()
{
    int n;
    cin >> n;
    cout << dec_to_bin(n) << endl;
    return 0;
}