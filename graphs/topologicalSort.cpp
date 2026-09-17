#include <bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    list<int>*l;
    bool isDirected;
public:
    Graph(int v,bool isDirected = false){
        this->v = v;
        this->isDirected = isDirected;
        l = new list<int>[v];
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
        if(!isDirected){
            l[v].push_back(u);
        }
    }

    void print(){
        for(int i=0;i<v;i++){
            cout<<i<<":";
            for(auto it : l[i]){
                cout<<it<<" ";
            }
            cout<<endl;
        }
    }
    void dfsHelper(int u,vector<bool>&vis,stack<int>&s){
        vis[u] = true;
        for(auto it : l[u]){
            if(!vis[it]){
                dfsHelper(it,vis,s);
            }
        }
        s.push(u);
    }

    void topologicalSort(){
        vector<bool>vis(v,false);
        stack<int>s;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                dfsHelper(i,vis,s);
            }
        }
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
    }
};


int main(){
    Graph g(6,true);
    g.addEdge(4,0);
    g.addEdge(5,0);
    g.addEdge(5,2);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(4,1);
    g.print();
    g.topologicalSort();
}

