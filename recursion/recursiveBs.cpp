#include <bits/stdc++.h>
using namespace std;
int bs(int a[],int st,int end,int key){
    if(st > end){
        return -1;
    }
    int mid = (st+end)/2;
    if(a[mid] == key){
        return mid;
    }
    else if(a[mid] > key){
        return bs(a,st,mid-1,key);
    }
    else{
        return bs(a,mid+1,end,key);
    }
} 
int main(){
    int n , key;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>key;
    int st = 0 , end = n-1;
    cout<<bs(a,st,end,key);
}