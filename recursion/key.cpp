#include <bits/stdc++.h>
using namespace std;
void search(int a[],int i,int n,int key){
    if(i == n){
        return;
    }
    if(a[i] == key){
        cout<<i<<" ";
    }
    return search(a,i+1,n,key);
}

int main(){
    int n , key;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>key;
    search(a,0,n,key);
}