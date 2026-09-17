#include <bits/stdc++.h>
using namespace std;

int numOfLongestIncreasingSubsequence(vector<int>&arr1){
    unordered_set<int>s(arr1.begin(),arr1.end());
    vector<int>arr2(s.begin(),s.end());
    sort(arr2.begin(),arr2.end());
    int n = arr1.size();
    int m = arr2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            
        }
    }
}
int main(){
    vector<int>arr1 = {1,3,5,4,7};

}