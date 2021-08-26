#include<iostream>
#include<math.h>
using namespace std;

int reverse(int n){
    int rev = 0;
    while(n>0){
        int ld = n%10;
        rev = rev*10 + ld;
        n = n/10;
    }
    return rev;
}

int bin_sum(int a, int b){
    int ans = 0;
    int prev_carry = 0;
    while(a>0 && b>0){
        if(a%10 == 0 && b%10 == 0){
            ans = ans*10 + prev_carry;
            prev_carry = 0;
        }
        else if ((a % 10 == 0 && b % 10 == 1) || (a % 10 == 1 && b % 10 == 0)){
            if(prev_carry == 0){
                ans = ans*10 + 1;
                prev_carry = 0;
            }
            else
            {
                ans = ans*10 + 0;
                prev_carry = 1;
            }
            
        }
        else{
            ans = ans*10 + prev_carry;
            prev_carry = 1;
        }
        a/=10;
        b/=10;
    }
    while(a>0){
        if(prev_carry==1){
            if(a%2 == 1){
                ans = ans * 10 + 0;
                prev_carry = 1;
            }
            else
            {
                ans = ans * 10 + 1;
                prev_carry = 0;
            }
        }
        else
        {
            ans = ans*10+(a%2);
        }
        a/=10;
    }
    while (b > 0)
    {
        if (prev_carry == 1)
        {
            if (b % 2 == 1)
            {
                ans = ans * 10 + 0;
                prev_carry = 1;
            }
            else
            {
                ans = ans * 10 + 1;
                prev_carry = 0;
            }
        }
        else
        {
            ans = ans*10 + (b % 2);
        }
        b /= 10;
    }
    if(prev_carry ==1){
        ans = ans * 10 + 1;
    }
    ans = reverse(ans);
    return ans;
}

int main(){
    int a, b;
    cin>>a>>b;
    cout<<bin_sum(a, b)<<endl;
    return 0;
}