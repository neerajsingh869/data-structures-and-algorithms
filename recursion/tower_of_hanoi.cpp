#include<iostream>
using namespace std;

void towerofHanoi(int n, char src, char helper, char dest){
    if(n == 0){
        return;
    }
    // Move n-1 disks from source to helper (helper -> dest)
    towerofHanoi(n-1, src, dest, helper);
    // Move nth disk from source to destination
    cout<<"Move from "<<src<<" to "<<dest<<endl;
    // Move n-1 disks from helper to destination
    towerofHanoi(n-1, helper, src, dest);
}

int main(){
    int n;
    cin>>n;
    towerofHanoi(n, 'A', 'B', 'C');
    return 0;
}