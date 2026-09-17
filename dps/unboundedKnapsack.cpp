#include <bits/stdc++.h>
using namespace std;

int main(){
    int wt = 7;
    vector<pair<int,int>>kap;
    kap.push_back({15,2});
    kap.push_back({14,5});
    kap.push_back({10,1});
    kap.push_back({45,3});
    kap.push_back({30,4});
    vector<vector<int>>dp(6,vector<int>(wt+1,0));
    for(int i=1;i<dp.size();i++){
        for(int j=1;j<dp[i].size();j++){
            int currVal  = kap[i-1].first;
            int currWt = kap[i-1].second;
            if(currWt <= j){
                int ans1 = dp[i-1][j];
                int ans2 = dp[i][j-currWt] + currVal;
                dp[i][j] = max(ans1,ans2);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[i].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<dp[5][wt];
    return 0;
} 