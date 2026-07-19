#include <bits/stdc++.h>
using namespace std;

int subArrayWith0(vector<int>arr){
    unordered_map<int,int>m;
    int sum=0;
    int ans=0;
    for(int i=0;i<arr.size();i++){
        sum += arr[i];
        if(m.count(sum)){
            int idx = m[sum];
            ans = max(ans,i-idx);
        }else{
            m[sum] = i;
        }
    }
    return ans;
}

int main(){
    vector<int>arr={15,-2,2,-8,1,7,10};
    cout<<subArrayWith0(arr);
    return 0;
}