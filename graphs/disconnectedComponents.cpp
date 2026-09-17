#include <bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    list<int>*l;
public:
    Graph(int v){
        this->v = v;
        l = new list<int>[v];
    }
    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void print(){
        for(int u=0;u<v;u++){
            list<int>neigh = l[u];
            cout<<u<<":";
            for(int v : neigh){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }
    void bfsHelper(int st,vector<bool>&vis){
        queue<int>q;
        q.push(st);
        vis[st] = true;
        while(q.size() > 0){
            int curr = q.front();
            q.pop();
            cout<<curr<<" ";
            for(auto it : l[curr]){
                if(!vis[it]){
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
        cout<<endl;
    }
    void bfs(){
        vector<bool>vis(v,false);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                bfsHelper(i,vis);
            }
        }
    }
    void dfsHelper(int u,vector<bool>&vis){
        vis[u] = true;
        cout<<u<<" ";
        for(auto it : l[u]){
            if(!vis[it]){
                dfsHelper(it,vis);
            }
        }
    }
    void dfs(){
        vector<bool>vis(v,false);
        for(int i=0;i<vis.size();i++){
            if(!vis[i]){
                dfsHelper(i,vis);
                cout<<endl;
            }
        }
    }
};


int main(){
    Graph g1(10);
    g1.addEdge(1,6);
    g1.addEdge(6,4);
    g1.addEdge(4,9);
    g1.addEdge(4,3);
    g1.addEdge(3,8);
    g1.addEdge(3,7);
    g1.addEdge(2,5);
    g1.addEdge(2,0);
    g1.print();
    cout<<"DFS is : ";
    g1.dfs();
    cout<<"BFS is : ";
    g1.bfs();
    return 0;
}