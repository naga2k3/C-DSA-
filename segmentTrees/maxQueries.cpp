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
        tree[node] = max(tree[2*node+1] , tree[2*node+2]);
    }
    int rangeMax(int qi,int qj,int si,int sj,int node){
        if(qj < si || sj < qi)return INT_MIN;
        else if(si >= qi && sj <= qj){
            return tree[node];
        }
        else{
            int mid = si+(sj-si)/2;
            return max(rangeMax(qi,qj,si,mid,2*node+1) ,rangeMax(qi,qj,mid+1,sj,2*node+2));
        }
    }
    void update(int idx,int val,int st,int end,int node){
        if(st == end){
            tree[node] = val;
            return;
        }
        int mid = st+(end-st)/2;
        if(st <= idx && idx <= mid){
            update(idx,val,st,mid,2*node+1);
        }else{
            update(idx,val,mid+1,end,2*node+2);
        }
        tree[node] = max(tree[2*node+1] , tree[2*node+2]);
    }
public:
    St(vector<int>&vec){
        n = vec.size();
        tree.resize(4*n);
        buildTree(vec,0,n-1,0);
    }

    int rangeQuery(int qi,int qj){
        return rangeMax(qi,qj,0,n-1,0);
    }

    void updateQuery(int idx,int val){
        update(idx,val,0,n-1,0);
    }

};
int main(){
    vector<int>vec{6,8,-1,2,17,1,3,2,4};
    int n = vec.size();
    St s1(vec);
    cout<<s1.rangeQuery(2,5)<<endl;
    cout<<s1.rangeQuery(5,8)<<endl;
    s1.updateQuery(4,5);
    cout<<s1.rangeQuery(0,8)<<endl;
}