#include <bits/stdc++.h>
using namespace std;
int indianCoins(vector<int>&denominations ,int n){
    int count =0;
    sort(denominations.begin() , denominations.end() , greater<int>());
    for(int i=0;i<denominations.size();i++){
        while(denominations[i] <= n){
            n -= denominations[i];
            count++;
        }
        if(n == 0) break;
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    vector<int>denominations={1,2,5,10,20,50,100,500,2000};
    cout<<indianCoins(denominations,n);
    return 0;
}