#include <bits/stdc++.h>
using namespace std;

void powerOf2(int num){
    if(((num) & (num-1)) == 0){
        cout<<"its is a power of 2 ";
    }
    else{
        cout<<"Not power of 2";
    }
}

int main(){
    int num;
    cin>>num;
    powerOf2(num);
}