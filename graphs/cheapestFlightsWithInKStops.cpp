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
    void cheapestFlightsWithInKStops(int src,int dest,int k){
        int ans=INT_MAX;
        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(v,INT_MAX);
        dist[src] = 0;
        q.push({src,{0,-1}});
        while(!q.empty()){
            int node = q.front().first;
            int wt  = q.front().second.first;
            int stops = q.front().second.second;
            q.pop();
            if(node == dest && stops <= k){
                ans = min(ans,wt);
            }
            for(auto it : l[node]){
                if(stops+1 <= k && dist[it.first] > dist[node] + it.second){
                    dist[it.first] = dist[node] + it.second;
                    q.push({it.first,{wt+it.second,stops+1}});
                }
            }
        }
        cout<<ans;
    }
};

int main(){
    Graph g(3,true);
    g.addEdge(0,1,100);
    g.addEdge(0,2,500);
    g.addEdge(1,2,100);
    g.cheapestFlightsWithInKStops(0,2,1);
}