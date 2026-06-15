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
Node* insert(Node* root , int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    }
    if(root->data < val){
        root->right =insert(root->right , val);
    }else{
        root->left = insert(root->left,val);
    }
    return root;
}
Node* buildTree(vector<int>&nodes , int n){
    Node* root = NULL;
    for(int i=0;i<n;i++){
        root = insert(root,nodes[i]);
    }
    return root;
}
void inOrder(Node* root){
    if(root == NULL) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
bool search(Node* root,int val){
    if(root == NULL)return false;
    if(root->data == val){
        return true;
    }else if(root->data > val){
        return search(root->left,val);
    }else{
        return search(root->right,val);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>tree(n);
    for(int i=0;i<n;i++){
        cin>>tree[i];
    }
    Node* root = buildTree(tree,n);
    int val;
    cin>>val;
    inOrder(root);
    cout<<endl;
    cout<<search(root,val);
    return 0;
}