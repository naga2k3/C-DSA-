#include <bits/stdc++.h>
using namespace std;
void nextGreater(vector<int>arr){
    vector<int>a(arr.size());
    stack<int>s;
    a[arr.size()-1] = -1;
    s.push(arr[arr.size()-1]);
    for(int i=arr.size()-2;i>=0;i--){
        while(!s.empty() && arr[i] >= s.top()){
            s.pop();
        }
        if(s.empty()){
            a[i] = -1;
        }else{
            a[i] = s.top();
        }
        s.push(arr[i]);
    }
    for(int i=0;i<arr.size();i++){
        cout<<a[i]<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    nextGreater(arr);
    return 0;
}