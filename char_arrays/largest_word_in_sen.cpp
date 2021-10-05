#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    cin.ignore();
    char arr[n+1];

    cin.getline(arr, n+1);
    cin.ignore();
    int maxLen = 0, currLen = 0;
    int st = 0;
    // Make i global to count acutal n
    int i = 0;
    for(i; arr[i] != '\0'; i++){
        if(arr[i] == ' '){
            if(currLen > maxLen){
                maxLen = currLen;
                st = i - maxLen;
            }
            currLen = 0;
            continue;
        }
        currLen++;
    }
    if(currLen > maxLen){
        maxLen = currLen;
        // Replace n with i since you can give input >= actual n
        st = i - maxLen;
    }
    cout<<"Actual Length of Sentence: "<<i<<endl;
    cout<<maxLen<<endl;
    for(int i=0; i<maxLen; i++){
        cout<<arr[i+st];
    }
    return 0;
}