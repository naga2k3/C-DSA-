#include <bits/stdc++.h>
using namespace std;
void heapify(int i ,vector<int>&a,int n){
    int left = 2*i+1;
    int right = 2*i+2;
    int maxIdx = i;
    while(left<n && a[left] > a[maxIdx]){
        maxIdx = left;
    }
    while(right < n && a[right] > a[maxIdx]){
        maxIdx = right;
    }
    if(maxIdx != i){
        swap(a[maxIdx] , a[i]);
        heapify(maxIdx,a,n);
    }
}
void heapSort(vector<int>&a){
    int n = a.size();
    for(int i=n/2-1;i>=0;i--){
        heapify(i,a,n);
    }
    for(int i=n-1;i>=0;i--){
        swap(a[0] ,a[i]);
        heapify(0,a,i);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    heapSort(a);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}