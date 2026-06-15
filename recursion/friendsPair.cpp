#include <bits/stdc++.h>
using namespace std;
int friendsPair(int n){
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    return friendsPair(n-1) + (n-1) * friendsPair(n-2);
}
int main(){
    int n;
    cin>>n;
    cout<<friendsPair(n);
}