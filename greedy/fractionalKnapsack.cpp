#include <bits/stdc++.h>
using namespace std;
void fractionalKnapsack(int value[] , int weight[] ,int totalWeight , int n){
    vector<pair<double,int>>p1(n,make_pair(0,0));
    double ans=0;
    for(int i=0;i<n;i++){
        p1[i] = make_pair(((double)value[i]/weight[i]),i);
    }
    sort(p1.begin(),p1.end(),[](pair<double,int>&p1 , pair<double,int>&p2){
        return p1.first > p2.first;
    });
    for(int i=0;i<n;i++){
        if(weight[p1[i].second] <= totalWeight){
            ans += value[p1[i].second];
            totalWeight -= weight[p1[i].second];
        }else{
            ans += p1[i].first * totalWeight;
            break;
        }
    }
    cout<<ans;
}
int main(){
    int n,w;
    cin>>n;
    int value[n];
    int weight[n];
    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    cin>>w;
    fractionalKnapsack(value,weight,w,n);
    return 0;
}