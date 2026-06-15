#include <bits/stdc++.h>
using namespace std;
int countNums(vector<int>& a,int num ,int st , int end){
    int count =0;
    for(int i=st;i<=end;i++){
        if(a[i] == num){
            count++;
        }
    }
    return count;
}
int majorityElementRec(vector<int>& a ,int st , int end){
    if(st == end){
        return a[st];
    }
    int mid = st+(end-st)/2;
    int left = majorityElementRec(a,0,mid);
    int right = majorityElementRec(a,mid+1,end);
    if(left == right){
        return left;
    }
    int leftCount  = countNums(a,left,st,end);
    int rightCount = countNums(a,right,st,end);
    return leftCount > rightCount ? left : right;
}
int majorityElement(vector<int>& a , int n){
    return majorityElementRec(a,0,n-1);
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<majorityElement(a,n);
}