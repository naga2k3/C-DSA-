#include <bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    list<pair<int,int>>*l;
public:
    Graph(int v){
        this->v = v;
        l = new list<pair<int,int>>[v];
    }
    void addEdge(int u,int v,int wt){
        l[u].push_back({v,wt});
    }
    void print(){
        for(int i=0;i<v;i++){
            cout<<i<<":";
            for(auto p : l[i]){
                cout<<"("<<p.first<< ","<<p.second<<")";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g1(5);
    g1.addEdge(0,1,4);
    g1.addEdge(1,2,2);
    g1.addEdge(1,3,6);
    g1.addEdge(2,3,5);
    g1.addEdge(2,4,-1);
    g1.print();
    return 0;
}
