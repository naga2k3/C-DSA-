#include <bits/stdc++.h>
using namespace std;

int solve(string s1,string s2){
    if(s1.empty() || s2.empty()) return 0;

    int n = s1.size();
    int m = s2.size();

    if(s1[n-1] == s2[m-1]){
        return 1+solve(s1.substr(0,n-1),s2.substr(0,m-1));
    }else{
        return max(solve(s1,s2.substr(0,m-1)),solve(s1.substr(0,n-1),s2));
    }
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
        int ans1 = solveMemoization(n-1,m,s1,s2,dp);
        int ans2 = solveMemoization(n,m-1,s1,s2,dp);
        return dp[n][m] = max(ans1,ans2);
    }
}
int solveTabulation(string &s1,string &s2){
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char a = s1[i-1];
            char b = s2[j-1];
            if(a == b){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                int ans1 = dp[i-1][j];
                int ans2 = dp[i][j-1];
                dp[i][j] = max(ans1,ans2);
            }
        }
    }
    return dp[n][m];
}

int main(){
    string s1 = "abcdge";
    string s2 = "abedg";
    cout<<solve(s1,s2)<<endl;
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    cout<<solveMemoization(n,m,s1,s2,dp)<<endl;
    cout<<solveTabulation(s1,s2);
}
