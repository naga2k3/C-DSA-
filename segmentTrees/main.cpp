#include <bits/stdc++.h>
using namespace std;

class St{
    int n;
    vector<int>tree;

    void buildTree(vector<int>&vec,int st,int end,int node){
        if(st == end){
            tree[node] = vec[st];
            return;
        }
        int mid = st+(end-st)/2;
        buildTree(vec,st,mid,2*node+1);
        buildTree(vec,mid+1,end,2*node+2);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
    int rangeSum(int qi,int qj,int si,int sj,int node){
        if(qj < si || sj < qi){
            return 0;
        }
        else if(si >= qi && sj <= qj){
            return tree[node];
        }
        else{
            int mid = si+(sj-si)/2;
            return rangeSum(qi,qj,si,mid,2*node+1) + rangeSum(qi,qj,mid+1,sj,2*node+2);
        }
    }
    void updateQuery(int idx,int val,int st,int end,int node){
        if(st == end){
            tree[node] = val;
            return;
        }
        int mid = st+(end-st)/2;
        if(st <= idx && idx <= mid){
            updateQuery(idx,val,st,mid,2*node+1);
        }else{
            updateQuery(idx,val,st,mid,2*node+2);
        }
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
public:
    St(vector<int>&vec){
        n = vec.size();
        tree.resize(4*n);
        buildTree(vec,0,n-1,0);
    }

    int rangeQuery(int qi,int qj){
        return rangeSum(qi,qj,0,n-1,0);
    }
    void update(int idx,int val){
        updateQuery(idx,val,0,n-1,0);
    }
};

int main(){
    vector<int>vec{1,2,3,4,5,6,7,8};
    St s1(vec);
    cout<<s1.rangeQuery(2,5)<<endl;
    cout<<s1.rangeQuery(0,3)<<endl;
    cout<<s1.rangeQuery(6,7)<<endl;
    s1.update(1,3);
    cout<<s1.rangeQuery(2,5)<<endl;
    cout<<s1.rangeQuery(0,3)<<endl;
    cout<<s1.rangeQuery(6,7)<<endl;
}