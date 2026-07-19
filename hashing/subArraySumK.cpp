#include <bits/stdc++.h>
using namespace std;

int subArraySumK(vector<int>arr,int k){
    unordered_map<int,int>s;
    int sum=0;
    int count=0;
    s[0]=1;
    for(int i=0;i<arr.size();i++){
        sum += arr[i];
        if(s.count(sum-k)){
            count += s[sum-k];
        }
        s[sum]++;
    }
    return count;
}
int main(){
    vector<int>arr={10,2,-2,-20,10};
    int k;
    cin>>k;
    cout<<subArraySumK(arr,k);
}