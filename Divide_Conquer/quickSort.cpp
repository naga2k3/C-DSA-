#include <bits/stdc++.h>
using namespace std;
int partition(vector<int>& a,int st , int end){
    int i = st-1;
    int pivot= a[end];
    for(int j=st;j<end;j++){
        if(a[j]<=pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    i++;
    swap(a[i],a[end]); 
    return i;
}
void quickSort(vector<int>& a, int st , int end){
    if(st >= end) return;
    int pI = partition(a,st,end);
    quickSort(a,st,pI-1);
    quickSort(a,pI+1,end);
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quickSort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}