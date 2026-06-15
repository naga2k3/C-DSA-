#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long power(long long a, long long b){
    if(b==0) return 1;
    long long half = power(a,b/2);
    if(b%2==0)
        return (half*half)%MOD;
    else
        return (((half*half)%MOD)*a)%MOD;
    }
int countGoodNumbers(long long n){
    long long even;
    long long odd;
    if(n&1){
        odd = n/2;
        even = (n+1)/2;
    }
    else{
        even = n/2;
        odd = n/2;
    }
    return (power(5,even)*power(4,odd)) % MOD;
}

int main(){
    int n;
    cin>>n;
    cout<<countGoodNumbers(n);
}