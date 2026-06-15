#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int orginal_N = n;
    int sum = 0;
    while(n>0){
        int LD = n%10;
        sum = sum + pow(LD,3);
        n = n/10; 
    }
    if(sum == orginal_N){
        cout<<"Arm Strong";
    }
    else{
        cout<<"It is not a Arm strong";
    }
}