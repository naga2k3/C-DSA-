#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &length){
    int ans=0;
    priority_queue<int,vector<int>,greater<int>>pq(length.begin() , length.end());
    while(pq.size() > 1){
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();
        ans += min1 + min2;
        pq.push(min1 + min2);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>length(n);
    for(int i=0;i<n;i++){
        cin>>length[i];
    }
    cout<<solve(length);
    return 0;
}