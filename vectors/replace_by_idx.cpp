#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool myCompare(pair<int, int> a, pair<int, int> b){
    return a.first<b.first; 
}

int main(){
    int arr[] = {10,16,7,14,5,3,12,9};
    // Declaration of vectors of pairs
    vector < pair<int, int> > v;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n; i++){
        pair<int, int> p;   // temp pair
        p.first = arr[i];
        p.second = i;
        v.push_back(p);
        // v.push_back(make_pair(arr[i], i))
    }
    // Sorting the vector
    sort(v.begin(), v.end(), myCompare);
    // Main work
    for(int i = 0; i < v.size(); i++){
        arr[v[i].second] = i;
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    // for(auto element:v){
    //     cout<<element.second<<"->";
    //     cout<<element.first<<endl;
    // }
    return 0;
}