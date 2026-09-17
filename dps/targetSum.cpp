#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>arr{4,2,7,1,3};
    int targetSum = 7;
    vector<vector<int>>dp(6,vector<int>(8,0));
    for(int i=1;i<dp.size();i++){
        for(int j=1;j<dp[i].size();j++){
            int currWt = arr[i-1];
            if(currWt > j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i-1][j] , dp[i-1][j-currWt]+currWt);
            }
        }
    }
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[i].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}