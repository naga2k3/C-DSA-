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
bool isTrue(Node* root,Node* minVal , Node* maxVal){
    if(root == NULL) return true;
    if(minVal != NULL && minVal->data > root->data){
        return false;
    }
    if(maxVal != NULL && root->data > maxVal->data){
        return false;
    }
    return isTrue(root->left,minVal,root) && isTrue(root->right,root,maxVal);
}
bool validateBst(Node* root){
    return isTrue(root,NULL,NULL);
}
int main(){
    int n;
    cin>>n;
    vector<int>tree(n);
    for(int i=0;i<n;i++){
        cin>>tree[i];
    }
    Node* root = buildTree(tree,n);
    inOrder(root);
    cout<<endl;
    cout<<validateBst(root);
    return 0;
}