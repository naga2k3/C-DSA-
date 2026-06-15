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
Node* lca(Node* root,int n1 ,int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    Node* left = lca(root->left,n1,n2);
    Node* right = lca(root->right,n1,n2);
    if(left && right){
        return root;
    }
    return left == NULL ? right : left;
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
    cout<<lca(root,n1,n2)->data;
    return 0;
}