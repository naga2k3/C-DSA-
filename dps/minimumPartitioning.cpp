#include <bits/stdc++.h>
using namespace std;


int main(){
    vector<int>nums{1,6,11,5};
    int sum = 0;
    for(int x : nums){
        sum += x;
    }
    int target = sum/2;
    int n = nums.size();
    vector<vector<int>>dp(n+1,vector<int>(target+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            int curr = nums[i-1];
            if(curr <= j){
                dp[i][j] = max(curr+dp[i-1][j-curr],dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<(sum - dp[n][target]) - dp[n][target];
}
