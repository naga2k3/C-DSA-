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

    void allPathsUsingDfs(int u,int dest,vector<bool>&vis,string ans){
        if(u == dest){
            ans += to_string(u);
            cout<<ans<<endl;
            return;
        }
        vis[u] = true;
        for(auto it : l[u]){
            if(!vis[it]){
                allPathsUsingDfs(it,dest,vis,ans+to_string(u)+"->");
            }
        }
        vis[u] = false;
    }

    void allPathsUsingBfs(int st,int dest){
        queue<pair<int,string>>q;
        q.push({st,to_string(st)});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            if(curr.first == dest){
                cout<<curr.second<<endl;
                continue;
            }
            for(auto it : l[curr.first]){
                q.push({it,curr.second+"->"+to_string(it)});
            }
        }
    }

    void allPaths(int st,int dest){
        vector<bool>vis(v,false);
        allPathsUsingDfs(st,dest,vis,""); 
        allPathsUsingBfs(st,dest);
    }
};

int main(){
    Graph g(6,true);
    g.addEdge(0,3);
    g.addEdge(1,4);
    g.addEdge(4,0);
    g.addEdge(3,1);
    g.addEdge(2,3);
    g.addEdge(5,0);
    g.addEdge(5,2);
    g.print();
    g.allPaths(5,1);
    return 0;
}