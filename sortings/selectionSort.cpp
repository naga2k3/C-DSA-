#include <bits/stdc++.h>
using namespace std;

void selectionSort(int a[] , int n){
    for(int i=0;i<n-1;i++){
        int sidx = i;
        for(int j=i+1;j<n;j++){
            if(a[sidx] > a[j]){
                sidx = j;
            }
            swap(a[sidx] , a[i]);
        }
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
    selectionSort(a,n);
}