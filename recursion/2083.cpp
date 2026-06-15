#include <bits/stdc++.h>
using namespace std;

int cs(string s, int i,int j,int n){
    if(n == 1){
        return 1;
    }
    if(n <= 0){
        return 0;
    }
    int res = cs(s,i+1,j,n-1) + cs(s,i,j-1,n-1) - cs(s,i+1,j-1,n-2);
    if(s[i] == s[j]){
        res++;
    }
    return res;
}

int main(){
    string s;
    getline(cin,s);
    int n = s.size();
    cout<<cs(s,0,n-1,n);
}