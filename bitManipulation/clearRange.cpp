#include <bits/stdc++.h>
using namespace std;

int clearRange(int n,int i ,int j){
    int a = (~0)<<j+1;
    int b = (1<<i)-1;
    int bitmask = a | b;
    return (n & bitmask);
}

int main(){
    int num,i,j;
    cin>>num>>i>>j;
    cout<<clearRange(num,i,j);
}