#include <bits/stdc++.h>
using namespace std;
class Graph{
    int v;
    list<pair<int,int>>*l;
    int wt;
    bool isDirected;
public:
    Graph(int v,bool isDirected = false){
        this->v = v;
        l = new list<pair<int,int>>[v];
        this->isDirected = isDirected;
    }
    void addEdge(int u ,int v,int wt){
        l[u].push_back({v,wt});
        if(!isDirected){
            l[v].push_back({u,wt});
        }
    }
    void primsAlgorithm(int src){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<bool>mst(v,false);
        int finalCost = 0;
        pq.push({0,src});
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            if(mst[curr.second])continue;
            finalCost += curr.first;
            mst[curr.second] = true;
            for(auto it : l[curr.second]){
                if(!mst[it.first]){
                    pq.push({it.second , it.first});
                }
            }
        }
        cout<<finalCost<<"";
    }
};

int main(){
    Graph g(4);
    g.addEdge(0,1,10);
    g.addEdge(0,2,15);
    g.addEdge(0,3,30);
    g.addEdge(1,3,40);
    g.addEdge(2,3,50);
    g.primsAlgorithm(0);
}