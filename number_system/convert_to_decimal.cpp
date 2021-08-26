#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int bin_to_dec(int num){
    int dec=0;
    int i=0;
    while(num>0){
        int lastdigit = num%10;
        dec += lastdigit*pow(2, i);
        num = num/10;
        i++;
    }
    return dec;
}

int oct_to_dec(int num)
{
    int dec = 0;
    int i = 0;
    while (num > 0)
    {
        int lastdigit = num % 10;
        dec += lastdigit * pow(8, i);
        num = num / 10;
        i++;
    }
    return dec;
}

int hex_to_dec(string num)
{
    int dec = 0;
    int j = 0;
    int s = num.size();
    for(int i=s-1; i>=0; i--){
        if(num[i] >= '0' && num[i] <= '9'){
            dec += (num[i]-'0')*pow(16, j);
        }
        else if(num[i] >= 'A' && num[i] <= 'F'){
            dec += (num[i] - 'A' + 10) * pow(16, j);
        }
        j++; 
    }
    return dec;
}

int main(){
    string n;
    cin>>n;
    cout<<hex_to_dec(n)<<endl;
    return 0;
}