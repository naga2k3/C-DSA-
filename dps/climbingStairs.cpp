#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int>f(n+1,0);
    f[0] = 1;
    f[1] = 1;
    f[2] = 2;
    for(int i=3;i<=n;i++){
        f[i] = f[i-1] + f[i-2] + f[i-3];
    }
    cout<<f[n];
}