#include <bits/stdc++.h>
using namespace std;

void kadanes(int a[],int n){
    int maxSum = INT_MIN;
    int currSum = 0;
    for(int i=0; i<n; i++){
        currSum += a[i]; 
        maxSum = max(currSum , maxSum);
        if(currSum < 0){
            currSum = 0;
        }
    }
    cout<<maxSum;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    kadanes(a,n);
}