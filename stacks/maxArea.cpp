#include <bits/stdc++.h>
using namespace std;

void maxArea(vector<int> arr){
    stack<int>s;
    vector<int>a(arr.size());
    a[0] = -1;
    s.push(0);
    for(int i=1;i<arr.size();i++){
        while(!s.empty() && arr[i] <= arr[s.top()]){
            s.pop();
        }
        if(s.empty()){
            a[i] = -1;
        }else{
            a[i] = s.top();
        }
        s.push(i);
    }
    for(int i=0;i<arr.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    vector<int>a1(arr.size());
    stack<int>s1;
    a1[arr.size()-1] = arr.size();
    s1.push(arr.size()-1);
    for(int i=arr.size()-2;i>=0;i--){
        while(!s1.empty() && arr[i] <= arr[s1.top()]){
            s1.pop();
        }
        if(s1.empty()){
            a1[i] = arr.size();
        }else{
            a1[i] = s1.top();
        }
        s1.push(i);
    }
    for(int i=0;i<arr.size();i++){
        cout<<a1[i]<<" ";
    }
    vector<int>ans(arr.size());
    cout<<endl;
    int maxArea = INT_MIN;
    for(int i=0;i<arr.size();i++){
        int ans = arr[i] * (a1[i]-a[i]-1);
        cout<<ans<<" ";
        maxArea = max(maxArea , ans);
    }
    cout<<endl<<maxArea;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    maxArea(arr);
}
