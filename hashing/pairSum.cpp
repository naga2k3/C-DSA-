#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int target;
    cin>>target;
    unordered_map<int,int>m;
    for(int i=0;i<n;i++){
        int k = target-a[i];
        if(m.count(k)){
            cout<<m[k]<<" "<< i;
            break;
        }
        m[a[i]] = i;
    }
}