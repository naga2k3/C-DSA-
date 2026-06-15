#include <bits/stdc++.h>
using namespace std;
int search(vector<int>& a, int st , int end , int target){
    int mid = st + (end-st)/2;
    if(st > end) return -1;
    if(a[mid] == target){
        return mid;
    }
    else if(a[st] <=a[mid]){
        if(a[st]<=target && target <= a[mid]){
            return search(a,st,mid-1,target);
        }else{
            return search(a,mid+1,end,target);
        }
    }
    else{
        if(a[mid] <= target && target <= a[end]){
            return search(a,mid+1,end,target);
        }
        else{
            return search(a,st,mid-1,target);
        }
    }
}
int main(){
    int n,target;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>target;
    cout<<search(a,0,n-1,target);
}