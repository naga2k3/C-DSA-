#include <bits/stdc++.h>
using namespace std;

int tp(int n){
    if(n == 0 || n == 1){ // 2xn problem
        return 1;
    }
    return tp(n-1) + tp(n-2);
}

int main(){
    int n;
    cin>>n;
    cout<<tp(n);
}