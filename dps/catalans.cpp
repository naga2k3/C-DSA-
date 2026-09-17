#include <bits/stdc++.h>
using namespace std;

int catalans(int n){
    if(n == 0 || n == 1)return 1;
    int ans = 0;
    for(int i=0;i<n;i++){
        ans += catalans(i)*catalans(n-i-1);
    }
    return ans;
}
int catalansMemoization(int n,vector<int>&dp){
    if(n == 0 || n == 1)return 1;
    if(dp[n] != -1){
        return dp[n];
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans += catalansMemoization(i,dp) * catalansMemoization(n-i-1,dp);
    }
    return dp[n] = ans;
}
int catalansTabulation(int n){
    vector<int>dp(n+1,0);
    dp[0] = dp[1] = 1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    return dp[n];
}
int main(){
    int n =7;
    vector<int>dp(n+1,-1);
    cout<<catalans(n)<<" "<<catalansMemoization(n,dp)<<" "<<catalansTabulation(n)<<endl;
}