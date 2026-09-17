#include <bits/stdc++.h>
using namespace std;

int solve(vector<pair<int,int>>&kap,int wt,int n,vector<vector<int>>&dp){
    if(n ==0 || wt == 0){
        return 0;
    }
    if(dp[n][wt] != -1){
        return dp[n][wt];
    }
    int itemVal = kap[n-1].first;
    int itemWt = kap[n-1].second;
    
    if(itemWt > wt){
        return dp[n][wt] = solve(kap,wt,n-1,dp);
    }
    int ans1 = solve(kap,wt-itemWt,n-1,dp) + itemVal;
    int ans2 = solve(kap,wt,n-1,dp);
    return dp[n][wt] = max(ans1,ans2);
}

int main(){
    int wt = 7;
    vector<pair<int,int>>kap;
    kap.push_back({15,2});
    kap.push_back({14,5});
    kap.push_back({10,1});
    kap.push_back({45,3});
    kap.push_back({30,4});
    vector<vector<int>>dp(6,vector<int>(wt+1,-1));
    cout<<solve(kap,wt,5,dp)<<endl;
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[i].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<vector<int>>dp1(6,vector<int>(wt+1,0));
    for(int i=1;i<dp1.size();i++){
        for(int j=1;j<dp1[i].size();j++){
            int currVal = kap[i-1].first;
            int currWt = kap[i-1].second;
            if(currWt <= j){
                dp1[i][j] = max(dp1[i-1][j],dp1[i-1][j-currWt] + currVal);
            }else{
                dp1[i][j] = dp1[i-1][j];
            }
        }
    }
    cout<<endl;
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[i].size();j++){
            cout<<dp1[i][j]<<" ";
        }
        cout<<endl;
    }
}