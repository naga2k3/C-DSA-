#include <bits/stdc++.h>
using namespace std;

int divide(int dividend , int divisor){
    bool negative = (dividend < 0) ^ (divisor < 0);
    long long dvd = labs(dividend);
    long long dvs = labs(divisor);
    long long ans = 0;
    while(dvd >= dvs){
        long long temp = dvs , multiple = 1;
        while(dvs >= (temp << 1)){
            temp = temp << 1;
            multiple = multiple << 1;
        }
        dvd = dvd - temp;
        ans = ans + multiple;
    }
    return negative ? -ans : ans;
}

int main(){
    int dividend , divisor;
    cin>>dividend>>divisor;
    cout<<divide(dividend , divisor);
}