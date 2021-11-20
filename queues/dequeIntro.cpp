#include<iostream>
#include<deque>
using namespace std;

int main(){
    /* deque is called doubly ended queue. Pretty similar to vector 
    with some addition function like push_front, push_back, pop_front,
    pop_back, etc*/
    deque<int> dq;
    dq.push_front(1);
    dq.push_front(3);
    dq.push_back(5);
    dq.push_back(8);
    // Output method 1
    for(int i = 0; i<dq.size(); i++){
        cout<<dq[i]<<" ";
    }
    cout<<endl;
    // Output method 2
    for(auto i: dq){
        cout<<i<<" ";
    }
    cout << endl;
    dq.pop_front();
    dq.pop_back();
    for (auto i : dq)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}