#include <bits/stdc++.h>
using namespace std;

int getIthBit(int num , int i){
    // int bitmask = 1<<i;
    int bitmask = pow(2,i);
    if((num & bitmask) == 0){
        return 0;
    }
    else{
        return 1;
    }
}
int setIthBit(int num , int i){
    int bitmask = 1<<i;
    return(num | bitmask);
}

int clearIthBit(int num , int i){
    int bitmask = ~(1<<i);
    return(num & bitmask);
}

int main(){
    int num,i;
    cin>>num>>i;
    cout<<getIthBit(num,i)<<endl;
    cout<<setIthBit(num,i)<<endl;
    cout<<clearIthBit(num,i);
}
