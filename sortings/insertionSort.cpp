#include <bits/stdc++.h>
using namespace std;

void insertionSort(int a[] , int n){
    for(int i=1;i<n;i++){
        int curr = a[i];
        int prev = i-1;
        while(prev >= 0 && curr < a[prev]){
            swap(a[prev] , a[prev+1]);
            prev--;
        }
        a[prev+1] = curr;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}


int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    insertionSort(a,n);
}