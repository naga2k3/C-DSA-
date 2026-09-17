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
    void Bfs(){
        queue<int>q;
        vector<bool>visited(v,false);
        q.push(0);
        visited[0] = true;
        while(q.size() > 0){
            int curr = q.front();
            q.pop();
            cout<<curr<<" ";
            for(auto it : l[curr]){
                if(!visited[it]){
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
        cout<<endl;
    }
};

int main(){
    Graph g1(7);
    g1.addEdge(0,1);
    g1.addEdge(0,2);
    g1.addEdge(1,3);
    g1.addEdge(2,4);
    g1.addEdge(3,4);
    g1.addEdge(3,5);
    g1.addEdge(4,5);
    g1.addEdge(6,5);
    g1.print();
    g1.Bfs();
    return 0;
}