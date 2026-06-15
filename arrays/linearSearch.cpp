#include <bits/stdc++.h>
using namespace std;
int linearSearch(int n,int a[],int key){
    for(int i=0;i<n;i++){
        if(key == a[i]){
            return i;
        }
    }
    return -1;
}
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"your values are : ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"Enter the value to be find: ";
    int key;
    cin>>key;
    cout<<linearSearch(n,a,key);
}