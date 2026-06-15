#include <bits/stdc++.h>
using namespace std;

double pow(int x , int n){
    if(n == 0){
        return 1;
    }
    int halfPow = pow(x , n/2);
    int halfPowSquare = halfPow * halfPow;
    if(n%2 != 0){
        return x * halfPowSquare;
    }
    return halfPowSquare;
}

int main(){
    int x ,n;
    cin>>x>>n;
    cout<<pow(x , n);
}