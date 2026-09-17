#include <bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    list<int>*l;
    bool isDirected;
public: 
    Graph(int v, bool isDirected = false){
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
            for(auto v : l[i]){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }
    bool bipartite(){
        vector<int>color(v,-1);
        queue<int>q;
        for(int i=0;i<v;i++){
            if(color[i] != -1)continue;
            q.push(i);
            color[i] = 0;
            while(!q.empty()){
                int u  = q.front();
                q.pop();
                for(auto it : l[u]){
                    if(color[it] == -1){
                        q.push(it);
                        color[it] = 1 - color[u];
                    }
                    else if(color[it] == color[u])return false;
                }
            }
        }
        return true;
    }
};


int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,3);
    g.addEdge(3,2);
    g.addEdge(2,0);
    g.print();
    if(g.bipartite()){
        cout<<"it is Bipartite";
    }else{
        cout<<"it is not Bipartite";
    }
    return 0;
}