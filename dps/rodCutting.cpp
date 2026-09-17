#include <bits/stdc++.h>
using namespace std;

int solve(int n,vector<int>&price,vector<int>&len,vector<vector<int>>&dp,int l){
    if(l == 0 || n == 0)return 0;
    int currPrice = price[n-1];
    int currLen = len[n-1];
    if(dp[n][l] != -1){
        return dp[n][l];
    }
    if(currLen <= l){
        int ans1 = solve(n,price,len,dp,l-currLen) + currPrice;
        int ans2 = solve(n-1,price,len,dp,l);
        return dp[n][l] = max(ans1,ans2);
    }else{
        return dp[n][l] = solve(n-1,price,len,dp,l);
    }
}
int main(){
    vector<int>price{1,5,8,9,10,17,17,20};
    vector<int>len{1,2,3,4,5,6,7,8};
    int n = len.size();
    int rodLen = 8;
    vector<vector<int>>dp(n+1,vector<int>(rodLen+1,-1));
    cout<<solve(n,price,len,dp,rodLen)<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=rodLen;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}