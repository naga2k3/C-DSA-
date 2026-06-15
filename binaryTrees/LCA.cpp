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
bool path(Node* root , vector<int>&ans , int n){
    if(root == NULL){
        return false;
    }
    ans.push_back(root->data);
    if(root->data == n){ 
        return true;
    }
    bool left_path = path(root->left,ans,n);
    bool right_path = path(root->right,ans,n);
    if(left_path || right_path){
        return true;
    }
    ans.pop_back();
    return false;
}
int lca(Node* root,int n1 , int n2){
    vector<int>path1;
    vector<int>path2;
    path(root,path1,n1);
    path(root,path2,n2);
    int lca = -1;
    for(int i=0,j=0;i<path1.size() && j<path2.size();i++,j++){
        if(path1[i] != path2[j]){
            return lca;
        }
        lca = path1[i];
    }
    return lca;
}
int main(){
    int n;
    cin>>n;
    vector<int>tree(n);
    for(int i=0;i<n;i++){
        cin>>tree[i];
    }
    Node* root = buildTree(tree);
    int n1,n2;
    cin>>n1>>n2;
    cout<<lca(root,n1,n2);
    return 0;
}