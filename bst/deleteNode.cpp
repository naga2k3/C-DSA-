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
Node* getInorderSuccessor(Node* root){
    while(root->left){
        root = root->left;
    }
    return root;
}
Node* deleteNode(Node* root,int val){
    if(root == NULL) return NULL;
    if(root->data > val){
        root->left = deleteNode(root->left,val);
    }else if(root->data < val){
        root->right = deleteNode(root->right,val);
    }else{
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }else if(root->left == NULL || root->right == NULL){
            return root->left == NULL ? root->right : root->left;
        } 
        Node* LS = getInorderSuccessor(root->right);
        root->data = LS->data; 
        root->right  = deleteNode(root->right,LS->data);
        return root;
    }
    return root;
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
    deleteNode(root,val);
    inOrder(root);
    return 0;
}