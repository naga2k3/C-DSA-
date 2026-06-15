#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& a,int st,int mid,int end){
    vector<int>temp;
    int i=st,j=mid+1;
    while(i<=mid && j<=end){
        if(a[i] <= a[j]){
            temp.push_back(a[i++]);
        }else{
            temp.push_back(a[j++]);
        }
    }
    while(i<=mid){
        temp.push_back(a[i++]);
    }
    while(j<=end){
        temp.push_back(a[j++]);
    }
    for(int idx=st,x=0;idx<=end;idx++){
        a[idx] = temp[x++];
    }
}
void mergeSort(vector<int>& a, int st , int end){
    if(st >= end) return;
    int mid = (st+end)/2;
    mergeSort(a,st,mid);
    mergeSort(a,mid+1,end);
    merge(a,st,mid,end);
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mergeSort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}