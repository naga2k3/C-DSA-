#include <bits/stdc++.h>
using namespace std;

int fib(int n,vector<int>&f){
    if(n ==0 || n == 1){
        return n;
    }
    if(f[n] != -1){
        return f[n];
    }
    f[n] = fib(n-1,f) + fib(n-2,f);
    return f[n];
}
int main(){
    int n;
    cin>>n;
    vector<int>f(n+1,-1);
    cout<<fib(n,f);
}