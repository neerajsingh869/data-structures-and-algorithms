#include<bits/stdc++.h>
using namespace std;

int bin_to_dec(int num)
{
    int dec = 0;
    int i = 0;
    while (num > 0)
    {
        int lastdigit = num % 10;
        dec += lastdigit * pow(2, i);
        num = num / 10;
        i++;
    }
    return dec;
}

int dec_to_bin(int num)
{
    int bin = 0;
    int i = 0;
    // i represent the highest power that divides the decimal number.
    while (pow(2, i) <= num)
        i++;
    for (int j = i - 1; j >= 0; j--)
    {
        int quo = num / pow(2, j);
        bin = bin * 10 + quo;
        num -= quo * pow(2, j);
    }
    return bin;
}

int main(){
    int a, b;
    cin>>a>>b;
    int c = bin_to_dec(a);
    int d = bin_to_dec(b);
    int sum = c+d;
    cout<< dec_to_bin(sum) <<endl;
    return 0;
}