#include <bits/stdc++.h>
using namespace std;

void maxProdSubArray(int a[],int n){
    int maxProduct = INT_MIN;
    int prod=1;
    for(int i=0;i<n;i++){
        prod = prod * a[i];
        maxProduct = max(maxProduct , prod);
        if(prod < 0){
            prod = 0;
        }
    }
    cout<<maxProduct<<endl;
}


int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    maxProdSubArray(a,n);
}