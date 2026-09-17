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
        for(int i=0;i<v;i++){
            cout<<i<<":";
            for(int j : l[i]){
                cout<<j<<" ";
            }
            cout<<endl;
        }   
    }

    bool hasPathhelper(int src,int dest,vector<bool>&vis){
        if(src == dest){
            cout<<src<<endl;
            return true;
        }
        vis[src] = true;
        cout<<src<<"->";
        for(auto it : l[src]){
            if(!vis[it]){
                if(hasPathhelper(it,dest,vis)){
                    return true;
                }
            }
        }
        return false;
    }

    bool hasPath(int src,int dest){
        vector<bool>vis(v,false);
        return hasPathhelper(src,dest,vis);
    }

    bool hasPath1(int src,int dest){
        queue<int>q;
        vector<bool>vis(v,false);
        q.push(src);
        vis[src]=true;
        while(q.size() > 0){
            auto curr = q.front();
            q.pop();
            if(curr == dest){
                return true;
            }
            for(auto it : l[curr]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = true;
                }
            }
        }
        return false;
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
    g1.print();
    if(g1.hasPath(0,6)){
        cout<<"true";
    }else{
        cout<<"false"<<endl;
    }
    if(g1.hasPath1(0,6)){
        cout<<"true";
    }else{
        cout<<"false";
    }
    return 0;
}