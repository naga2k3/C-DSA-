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
    int ans = INT_MAX;
    bool cycleDirected(int u,vector<bool>&vis,vector<bool>&rec,vector<int>&depth){
        vis[u] = true;
        rec[u] = true;
        for(auto it : l[u]){
            if(!vis[it]){
                depth[it] = depth[u]+1;
                if(cycleDirected(it,vis,rec,depth)){
                    return true;
                }
                
            }else if(rec[it]){
                ans = min(ans,depth[u]-depth[it]+1);
                return true;
            }
        }
        rec[u] = false;
        return false;
    }
    void dfs(){
        vector<bool>vis(v,false);
        vector<bool>rec(v,false);
        vector<int>depth(v);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(cycleDirected(i,vis,rec,depth)){
                    cout<<"Cycle detected in Directed \n";
                    cout<<ans<<endl;
                    return;
                }
            }
        }
        cout<<"No Cycle Found";
    }
};

int main(){
    Graph g1(4);
    g1.addEdge(1,0);
    g1.addEdge(0,2);
    g1.addEdge(2,3);
    g1.addEdge(3,0);
    g1.print();
    g1.dfs();
    return 0;
}