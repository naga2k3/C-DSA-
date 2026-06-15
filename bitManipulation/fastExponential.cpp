#include <bits/stdc++.h>
using namespace std;

void fastExponential(int x,int n){
    int ans =1;
    while(n>0){
        int LD = n & 1;
        if(LD == 1){
            ans = ans * x;
        }
        x = x*x;
        n = n>>1;
    }
    cout<<ans;
}
int main(){
    int x,n;
    cin>>x>>n;
    fastExponential(x,n);
}