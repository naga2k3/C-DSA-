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

    void calIndegree(vector<int> &indeg){
        for(int i=0;i<v;i++){
            for(auto it : l[i]){
                indeg[it]++;
            }
        }
    }

    void kahns(){
        vector<int>indeg(v,0);
        calIndegree(indeg);
        queue<int>q;
        for(int i=0;i<v;i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto curr = q.front();
            cout<<q.front()<<" ";
            q.pop();
            for(auto it : l[curr]){
                indeg[it]--;
                if(indeg[it] == 0){
                    q.push(it);
                }
            }
        }
        cout<<endl;
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
    g.kahns();
}