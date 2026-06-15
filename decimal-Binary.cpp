#include <bits/stdc++.h>
using namespace std;

int main(){
    int decimal;
    cin>>decimal;
    int index=0 , binary[32];
    if(decimal == 0){
        cout<<0;
    }
    while(decimal>0){
        binary[index] = decimal%2;
        decimal = decimal/2;
        index++;
    }
    for(int i=index-1; i>=0; i--){
        cout<<binary[i];
    }
}