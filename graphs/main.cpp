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
};

int main(){
    Graph g1(5);
    g1.addEdge(0,1);
    g1.addEdge(1,2);
    g1.addEdge(1,3);
    g1.addEdge(2,3);
    g1.addEdge(2,4);
    g1.print();
    return 0;
}