#include <bits/stdc++.h>
using namespace std;

int BS(int a[],int n,int key){
    int start = 0;
    int end = n-1;
    while(start <= end){
        int mid=(start+end)/2;
        if(a[mid] == key){
            return mid;
        }
        else if(a[mid] < key){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int key;
    cin>>key;
    cout<<BS(a,n,key);
}