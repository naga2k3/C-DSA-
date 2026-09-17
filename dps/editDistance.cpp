#include <bits/stdc++.h>
using namespace std;

int editDistance(string &s1, string &s2){
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0] = i;
    }
    for(int j=0;j<=m;j++){
        dp[0][j] = j;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                int ans1 = dp[i][j-1]; //insert
                int ans2 = dp[i-1][j-1]; //replace
                int ans3 = dp[i-1][j]; //delete
                dp[i][j] = 1 + min({ans1,ans2,ans3});
            }
        }
    }
    return dp[n][m];
}
int main(){
    string s1;
    string s2;
    getline(cin,s1);
    getline(cin,s2);
    cout<<editDistance(s1,s2);
}