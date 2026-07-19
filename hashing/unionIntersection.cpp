#include <bits/stdc++.h>
using namespace std;

void unionIntersection(vector<int>arr1,vector<int>arr2){
    unordered_set<int>u;
    unordered_set<int>i;
    for(int x:arr1){
        u.insert(x);
        i.insert(x);
    }
    for(int x : arr2){
        u.insert(x);
    }
    cout<<"Union:";
    for(int el : u){
        cout<<el<<" ";
    }
    cout<<endl;
    cout<<"Intersection:";
    for(int x : arr2){
        if(i.find(x) != i.end()){
            cout<<x<<" ";
            i.erase(x);
        }
    }
}
int main(){
    vector<int>arr1={7,3,9};
    vector<int>arr2={6,3,9,2,9,4};
    unionIntersection(arr1,arr2);
}