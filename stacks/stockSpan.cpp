#include <bits/stdc++.h>
using namespace std;
void stockSpan(vector<int>arr){
    stack<int>s;
    vector<int>a(arr.size());
    a[0] = 0;
    s.push(0);
    for(int i=1;i<arr.size();i++){
        while(!s.empty() && arr[i] >= arr[s.top()]){
            s.pop();
        }
        if(s.empty()){
            a[i] = i+1;
        }else{
            a[i] = i- s.top();
        }  
        s.push(i); 
    }
    for(int i=0;i<a.size();i++){
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
    stockSpan(arr);
    return 0;
}