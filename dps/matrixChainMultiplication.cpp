#include <bits/stdc++.h>
using namespace std;
int mcm(int st,int end,vector<int>&arr){
    if(st == end)return 0;
    int ans = INT_MAX;
    for(int i=st;i<end;i++){
        int left = mcm(st,i,arr);
        int right = mcm(i+1,end,arr);
        int currAns = left + right + (arr[st-1]*arr[i]*arr[end]);
        ans = min(ans,currAns);
    }
    return ans;
}
int mcmcMemoization(int st,int end,vector<int>&arr,vector<vector<int>>&dp){
    if(st == end)return 0;
    if(dp[st][end] != -1){
        return dp[st][end];
    }
    int ans = INT_MAX;
    for(int i=st;i<end;i++){
        int ans1 = mcmcMemoization(st,i,arr,dp);
        int ans2 = mcmcMemoization(i+1,end,arr,dp);
        int curr = ans1 + ans2 + (arr[st-1]*arr[i]*arr[end]);
        ans = min(ans,curr);
    }
    return dp[st][end] = ans;
}
int mcmTabulation(vector<int>&arr){
    int n = arr.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int len=2;len<n;len++){
        for(int i=1;i<=n-len;i++){
            int j=i+len-1;
            dp[i][j] = INT_MAX;
            for(int k=i;k<j;k++){
                int cost1 = dp[i][k];
                int cost2 = dp[k+1][j];
                int curr = cost1 + cost2 + (arr[i-1]*arr[k]*arr[j]);
                dp[i][j] = min(dp[i][j] , curr);
            }
        }
    }
    return dp[1][n-1];
}
int main(){
    vector<int>arr{1,2,3,4,3};
    int n = arr.size();
    cout<<mcm(1,n-1,arr)<<endl;
    vector<vector<int>>dp(n,vector<int>(n,-1));
    cout<<mcmcMemoization(1,n-1,arr,dp)<<" "<<mcmTabulation(arr);

}