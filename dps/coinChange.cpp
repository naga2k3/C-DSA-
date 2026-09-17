#include <bits/stdc++.h>
using namespace std;


int main(){
    int amount = 5;
    vector<int>coins{1,2,5};
    vector<vector<int>>dp(4,vector<int>(amount+1,0));
    for(int i=0;i<dp.size();i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<dp.size();i++){
        for(int j=1;j<dp[i].size();j++){
            if(coins[i-1] <= j){
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[3][amount]<<endl;
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[i].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
}