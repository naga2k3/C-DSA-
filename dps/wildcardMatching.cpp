#include <bits/stdc++.h>
using namespace std;

bool wildcardMatching(string &s1,string &s2){
    int n = s1.size();
    int m = s2.size();
    vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
    dp[0][0] = true;
    for(int j=1;j<=m;j++){
        if(s2[j-1] != '*'){
            dp[0][j] = false;
        }else{
            dp[0][j] = dp[0][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1] || s2[j-1] == '?'){
                dp[i][j] = dp[i-1][j-1];
            }else if(s2[j-1] == '*'){
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }else{
                dp[i][j] = false;
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
    cout<<wildcardMatching(s1,s2);
}