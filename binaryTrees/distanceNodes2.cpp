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
Node* LCA(Node* root,int n1 ,int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    Node* left = LCA(root->left,n1,n2);
    Node* right = LCA(root->right,n1,n2);
    if(left && right){
        return root;
    }
    return left == NULL ? right : left;
}
int dict(Node* root , int n){
    if(root == NULL) return -1;
    if(root->data == n){
        return 0;
    }
    int left = dict(root->left,n);
    if(left != -1){
        return left+1;
    }
    int right = dict(root->right,n);
    if(right != -1){
        return right+1;
    }
    return -1;
}
int minDict(Node* root,int n1,int n2){
    Node* lca = LCA(root,n1,n2);
    int dict1 = dict(lca,n1);
    int dict2 = dict(lca,n2);
    return dict1+dict2;
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
    cout<<minDict(root,n1,n2);
    return 0;
}