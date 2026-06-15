#include <bits/stdc++.h>
using namespace std;

bool isSorted(int a[] , int n ,int i){
    if(i == n-1){
        return true;
    }
    if(a[i] > a[i+1]){
        return false;
    }
    return isSorted(a,n,i+1);
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int i=0;
    cout<<isSorted(a , n ,i);
}