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
void printInRange(Node* root,int start,int end){
    if(root == NULL) return;
    if(root->data >= start && root->data <= end){
        printInRange(root->left,start,end);
        cout<<root->data<<" ";
        printInRange(root->right,start,end);
    }else if(root->data < start){
        printInRange(root->right,start,end);
    }else{
        printInRange(root->left,start,end);
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
    inOrder(root);
    cout<<endl;
    printInRange(root,5,12);
    return 0;
}