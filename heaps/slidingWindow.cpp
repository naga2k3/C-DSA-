#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>&a,int k){
    priority_queue<pair<int,int>>pq;
    for(int i=0;i<k;i++){
        pq.push(make_pair(a[i],i));
    }
    cout<<pq.top().first<<" ";
    for(int i=k;i<a.size();i++){
        while(!pq.empty() && pq.top().second <= i-k){
                pq.pop();
            }
        pq.push(make_pair(a[i],i));
        cout<<pq.top().first<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    solve(a,k);
    return 0;
}