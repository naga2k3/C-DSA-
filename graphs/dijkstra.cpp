#include <bits/stdc++.h>
using namespace std;

class Edge{
public:
    int v;
    int wt;
    Edge(int v,int wt){
        this->v = v;
        this->wt = wt;
    }
};
void dijkstra(int v,int src,vector<vector<Edge>> &graph){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dis(v,INT_MAX);
    pq.push({0,src});
    dis[src] = 0;
    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();
        for(auto it : graph[curr.second]){
            if(dis[it.v] > dis[curr.second] + it.wt){
                dis[it.v] = dis[curr.second] + it.wt;
                pq.push({dis[it.v],it.v});
            }
        }
    }
    for(auto it : dis){
        cout<<it<<" ";
    }
}
int main(){
    int v= 6;
    vector<vector<Edge>> graph(v);
    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));
    graph[1].push_back(Edge(2,1));
    graph[1].push_back(Edge(3,7));
    graph[2].push_back(Edge(4,3));
    graph[3].push_back(Edge(5,1));
    graph[4].push_back(Edge(3,2));
    graph[4].push_back(Edge(5,5)); 
    dijkstra(v,0,graph);
}