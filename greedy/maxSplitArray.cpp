#include <bits/stdc++.h>
using namespace std;
bool predicate(vector<int>&nums ,int k,int mid){
    int temp_k=1;
    int total = 0;
    for(auto num:nums){
        total += num;
        if(total>mid){
            temp_k++;
            total = num;
            if(temp_k > k){
                return false;
            }
        }
    }
    return true;
}
int splitArray(vector<int>&nums ,int k){
    int l = *max_element(nums.begin(),nums.end());
    int r = accumulate(nums.begin(), nums.end() , 0);
    while(l<r){
        int m = l+(r-l)/2;
        if(predicate(nums,k,m)){
            r = m;
        }else{
            l = m+1;
        }
    }
    return l;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int k;
    cin>>k;
    cout<<splitArray(nums,k);
}