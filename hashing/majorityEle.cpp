#include <bits/stdc++.h>
using namespace std;

void majorityEle(vector<int>arr){
    unordered_map<int,int>m;
    for(int x:arr){
        m[x]++;
    }
    for(pair<int,int> n : m){
        if(n.second > arr.size()/3){
            cout<<n.first<<" ";
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    majorityEle(arr);
    return 0;
}