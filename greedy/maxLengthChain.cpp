#include <bits/stdc++.h>
using namespace std;
int maxLength(vector<pair<int,int>> &arr , int n){
    sort(arr.begin(),arr.end(),[](pair<int,int> &p1 , pair<int,int> &p2){
        return p1.second<p2.second;
    });
    int count =1;
    int currEnd = arr[0].second;
    cout<<"p0"<<"->";
    for(int i=1;i<n;i++){
        if(currEnd <= arr[i].first){
            currEnd = arr[i].second;
            count++;
            cout<<"p"<<i<<"->";
        }
    }
    cout<<endl;
    return count;
}
    
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>arr(n,make_pair(0,0));
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
        cin>>arr[i].second;
    }
    cout<<maxLength(arr,n);
}