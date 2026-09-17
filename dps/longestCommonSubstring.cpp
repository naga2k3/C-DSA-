#include <bits/stdc++.h>
using namespace std;

int solve(int n,int m,string s1,string s2,int &ans){
    if(n == 0 || m == 0) return 0;

    if(s1[n-1] == s2[m-1]){
        int val = 1+solve(n-1,m-1,s1,s2,ans);
        ans = max(ans,val);
        return val;
    }
    return 0;
}
int solveMemoization(int n,int m,string &s1,string &s2,vector<vector<int>>&dp){
    if(n == 0 || m == 0)return 0;
    if(dp[n][m] != -1){
        return dp[n][m];
    }
    char a = s1[n-1];
    char b = s2[m-1];
    if(a == b){
        return dp[n][m] = 1 + solveMemoization(n-1,m-1,s1,s2,dp);
    }else{
        return dp[n][m] = 0;
    }
}
int solveTabulation(string &s1,string &s2){
    int n = s1.size();
    int m = s2.size();
    int ans = 0;
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans , dp[i][j]);
            }else{
                dp[i][j] = 0;
            }        
        }
    }
    return ans;
}
int main(){
    string s1 = "abcde";
    string s2 = "abgce";
    int n = s1.size();
    int m = s2.size();
    int result = 0;
    int ans = 0;
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            solve(i,j,s1,s2,ans);
            result = max(result,solveMemoization(i,j,s1,s2,dp));
        }
    }
    cout<<ans<<" "<<result<<" "<<solveTabulation(s1,s2)<<endl;
    
}
