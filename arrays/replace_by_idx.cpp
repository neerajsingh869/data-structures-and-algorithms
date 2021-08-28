#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ori[n];
    for(int i = 0; i < n; i++){
        cin>>ori[i];
    }
    int sorted[n];
    for(int i = 0; i < n; i++){
        sorted[i] = ori[i];
    }
    // Sorting algorithm -> Insertion sort (Can also use inbuilt sort() function under <algorithm> header file)
    for(int i = 1; i< n; i++){
        int current = sorted[i];
        int j = i-1;
        while(sorted[j]> current && j>=0){
            sorted[j+1] = sorted[j];
            j--;
        }
        sorted[j+1] = current;
    }
    // Actual work - replacing the numbers of original array from smallest to largest with numbers 0 to size - 1.
    for(int i = 0; i<n; i++){
        for(int j = 0; j < n; j++){
            if(sorted[i] == ori[j]){
                ori[j] = i;
                break;
            }
        }
    }
    // Output the array
    for(int i = 0; i < n; i++){
        cout<<ori[i]<<" ";
    }
    return 0;
}