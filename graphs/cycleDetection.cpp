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

    void addEdge(int v,int u){
        l[v].push_back(u);
        l[u].push_back(v);
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

    bool dfsHelper(int u,vector<bool>&vis,int parent){
        vis[u] = true;
        for(auto it : l[u]){
            if(!vis[it]){
                if(dfsHelper(it,vis,u)){
                    return true;
                }
            }
            else if(it != parent){
                cout<<"BackEdge is : "<<it<<" -> "<<u<<endl;
                return true;
            }
        }
        return false;
    }
    void dfs(){
        vector<bool>vis(v,false);
        if(dfsHelper(0,vis,-1)){
            cout<<"Cycle Detected \n";
        }else{
            cout<<"NO Cycle Detected \n";
        }
    }
};



int main(){
    Graph g1(5);
    g1.addEdge(0,1);
    g1.addEdge(0,2);
    g1.addEdge(2,1);
    g1.addEdge(0,3);
    g1.addEdge(3,4);
    g1.print();
    g1.dfs();
    return 0;
}