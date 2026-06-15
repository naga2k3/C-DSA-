#include <bits/stdc++.h>
using namespace std;

int countSetBits(int num ){
    int count = 0;
    while(num > 0){
        int LD = num & 1;
        count = count + LD;
        num = num >> 1;
    }
    return count;
}

int main(){
    int num,i;
    cin>>num;
    cout<<countSetBits(num);
}