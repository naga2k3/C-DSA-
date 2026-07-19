#include <bits/stdc++.h>
using namespace std;

class Row{
public:
    int count;
    int idx;
    Row(int count,int idx){
        this->count = count;
        this->idx = idx;
    }
    bool operator <(const Row &obj) const{
        if(this->count == obj.count){
            return this->idx > obj.idx;
        }
        return this->count > obj.count;
    }
};

void weakestSoldier(vector<vector<int>> &soldiers , int k){
    priority_queue<Row>pq;
    for(int i=0;i<soldiers.size();i++){
        int count = 0;
        for(int j=0;j<soldiers[i].size();j++){
            if(soldiers[i][j] == 1)count++;
        }
        pq.push(Row(count,i));
    }
    for(int i=0;i<k;i++){
        cout<<"R"<<pq.top().idx<<" ";
        pq.pop();
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>soldiers(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>soldiers[i][j];
        }
    }
    int k;
    cin>>k;
    weakestSoldier(soldiers,k);
    return 0;
}