#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    int start=0;
    int end=n-1;
    vector<int>ans;
    while(start < end){
        if(arr[start]+arr[end] == target){
            ans.push_back(start);
            ans.push_back(end);
            break;
        }
        else if(arr[start]+arr[end] > target){
            end--;
        }
        else{
            start++;
        }
    }
    cout<<ans[0]<<" "<<ans[1];
}