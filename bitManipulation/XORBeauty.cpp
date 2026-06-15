#include <bits/stdc++.h>
using namespace std;

int XorBeauty(vector<int>nums){
    // int xorValue = 0;
    // for(int i=0;i<nums.size();i++){
    //     for(int j=0;j<nums.size();j++){
    //         for(int k=0;k<nums.size();k++){
    //             xorValue = xorValue ^ ((nums[i]|nums[j]) & nums[k]);
    //         }
    //     }
    // }
    // return xorValue;
    int a=0,b=0;
     for(int i=0;i<nums.size();i++){
        a = a | nums[i];
        b = b ^ nums[i];
     }
     return (a&b);
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<XorBeauty(nums);
}