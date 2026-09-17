#include <bits/stdc++.h>
using namespace std;
class Edge{
public:
    int u;
    int v;
    int wt;
    Edge(int u,int v,int wt){
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};
class Graph{
public:
    int v;
    vector<Edge>edges;
    vector<int>rank;
    vector<int>par;

    Graph(int v){
        this->v = v;
        for(int i=0;i<v;i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }
    void addEdge(int u,int v,int wt){
        edges.push_back(Edge(u,v,wt));
    }
    int find(int x){
        if(par[x] == x){
            return x;
        }
        return par[x] = find(par[x]);
    }
    void unionByRank(int a,int b){
        int parA = find(a);
        int parB = find(b);
        if(rank[parA] == rank[parB]){
            par[parB] = parA;
            rank[parA]++;
        }else if(rank[parA] > rank[parB]){
            par[parB] = parA;
        }else{
            par[parA] = parB;
        }
    }
    void kruskalsAlgo(){
        sort(edges.begin(),edges.end(),[](Edge &a,Edge &b){
            return a.wt < b.wt;
        });
        int ans = 0;
        for(auto i : edges){
            int parU = find(i.u);
            int parV = find(i.v);
            if(parU == parV)continue;
            unionByRank(i.u,i.v);
            ans += i.wt;
        }
        cout<<ans<<" ";
    }
};

int main(){
    Graph g(4);
    g.addEdge(0,1,10);
    g.addEdge(0,2,15);
    g.addEdge(0,3,30);
    g.addEdge(1,3,40);
    g.addEdge(2,3,50);
    g.kruskalsAlgo();
}