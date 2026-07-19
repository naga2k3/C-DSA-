#include <bits/stdc++.h>
using namespace std;

int countDupli(vector<int>arr){
    unordered_set<int>m;
    for(int x : arr){
        m.insert(x);
    }
    return m.size();
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<countDupli(arr);
}