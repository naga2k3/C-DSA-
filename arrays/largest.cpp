#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int lidx = a[0];
    int sidx = a[0];
    for(int i=0;i<n;i++){
        if(lidx < a[i]){
            lidx = a[i];
        }
        if(sidx > a[i]){
            sidx = a[i];
        }
    }
    cout<<"Largest in the array is: "<<lidx<<endl;
    cout<<"Smallest in the array is: "<<sidx<<endl;
}