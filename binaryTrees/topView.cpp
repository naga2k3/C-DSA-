#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left=right=NULL;
    }
};
static int idx = -1;
Node* buildTree(vector<int>&nodes){
    idx++;
    if(nodes[idx] == -1){
        return NULL;
    }
    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);
    return currNode;
}
void horizontalDistance(Node* root){
    queue<pair<Node*,int>>q;
    map<int,int>m;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*,int> curr = q.front(); 
        q.pop();
        if(m.count(curr.second) == 0) m[curr.second] = curr.first->data;
        if(curr.first->left) q.push(make_pair(curr.first->left,curr.second-1));
        if(curr.first->right) q.push(make_pair(curr.first->right,curr.second+1)); 
    }
    
    for(auto it:m){
        cout<<it.second<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    vector<int>tree(n);
    for(int i=0;i<n;i++){
        cin>>tree[i];
    }
    Node* root = buildTree(tree);
    horizontalDistance(root);
    return 0;
}