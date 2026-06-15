#include <bits/stdc++.h>
using namespace std;

int firstoccurance(vector<int>ans , int target , int n , int i){
    if(i == n){
        return -1;
    }
    if(ans[i] == target){
        return i;
    }
    return firstoccurance(ans,target,n,i+1);
}
int main(){
    int n,target; 
    cin>>n;
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        cin>>ans[i];
    }
    int i=0;
    cin>>target;
    cout<<firstoccurance(ans , target , n , i);
}