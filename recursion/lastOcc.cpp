#include <bits/stdc++.h>
using namespace std;

int lastoccurance(vector<int>ans , int target , int n){
    if(n == -1){
        return -1;
    }
    if(ans[n] == target){
        return n;
    }
    return lastoccurance(ans,target,n-1);
}
int main(){
    int n,target;
    cin>>n;
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        cin>>ans[i];
    }
    cin>>target;
    cout<<lastoccurance(ans,target,n);
}