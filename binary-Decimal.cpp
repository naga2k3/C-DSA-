#include <bits/stdc++.h>
using namespace std;

int main(){
    int binary;
    cin>>binary;
    int decimal=0 ,base=1, remainder;
    while(binary>0){
        remainder = binary%2;
        decimal = decimal + remainder*base;
        base = base*2;
        binary = binary/10;
    }
    cout<<decimal;
}