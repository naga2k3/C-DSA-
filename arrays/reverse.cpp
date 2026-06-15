#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int end = n-1;
    for(int i=0;i<n;i++){
        if(i < end){
            int temp = a[i];
            a[i] = a[end];
            a[end] = temp;
            end--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}