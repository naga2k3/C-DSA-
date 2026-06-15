#include <bits/stdc++.h>
using namespace std;

void jobSequencing(vector<pair<int,int>>job){
    sort(job.begin(),job.end(),[](pair<int,int> &p1 , pair<int,int>&p2){
        return p1.second>p2.second;
    });
    int profit = job[0].second;
    int safeStart = 2;
    cout<<"{"<<job[0].first<<" "<<job[0].second<<"}";
    for(int i=1;i<job.size();i++){
        if(safeStart <= job[i].first){
            profit += job[i].second;
            safeStart++;
            cout<<" {"<<job[i].first<<" "<<job[i].second<<"}";
        }
    }
    cout<<endl;
    cout<<"Total Profit is : "<<profit;
}

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>job(n,make_pair(0,0));
    for(int i=0;i<n;i++){
        cin>>job[i].first;
        cin>>job[i].second;
    }
    jobSequencing(job);
    return 0;
}