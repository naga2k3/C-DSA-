#include <bits/stdc++.h>
using namespace std;


void longestIncreasingSubsequence(int idx,vector<int>&arr,int prev,int count,int &maxCount){
    if(idx == arr.size()){
        maxCount = max(maxCount,count);
        return;
    }
    int curr = arr[idx];
    if(curr > prev){
        longestIncreasingSubsequence(idx+1,arr,curr,count+1,maxCount);
    }
    longestIncreasingSubsequence(idx+1,arr,prev,count,maxCount);
}
int longestIncreasingSubsequenceTabulation(vector<int>&arr){
    unordered_set<int>s(arr.begin(),arr.end());
    vector<int>arr2(s.begin(),s.end());
    sort(arr2.begin(),arr2.end());
    int n = arr.size();
    int m = arr2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i-1] == arr2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{  
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][m];
}

int main(){
    vector<int>arr{50,3,10,7,40,80};
    int maxCount = INT_MIN;
    int count =0;
    longestIncreasingSubsequence(0,arr,INT_MIN,count,maxCount);
    cout<<maxCount<<" "<<endl;
    cout<<" "<<longestIncreasingSubsequenceTabulation(arr)<<endl;
}