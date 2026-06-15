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
bool isIdentical(Node* root , Node* subRoot){
    if(root == NULL && subRoot == NULL){
        return true;
    }else if(root == NULL || subRoot == NULL){
        return false;
    }
    if(root->data != subRoot->data) return false;
    return isIdentical(root->left,subRoot->left) && isIdentical(root->right,subRoot->right);
}
bool isSubTree(Node* root , Node* subRoot){
    if(root == NULL && subRoot == NULL){
        return true;
    }else if(root == NULL || subRoot == NULL){
        return false;
    }
    if(root->data == subRoot->data){
        if(isIdentical(root,subRoot)){
            return true;
        }
    }
    bool isLeftSubTree = isSubTree(root->left,subRoot);
    if(!isLeftSubTree){
        return isSubTree(root->right,subRoot);
    } 
    return true;
}
int main(){
    int n;
    cin>>n;
    vector<int>tree(n);
    for(int i=0;i<n;i++){
        cin>>tree[i];
    }
    Node* root = buildTree(tree);
    int m;
    cin>>m;
    vector<int>subTree(m);
    for(int i=0;i<m;i++){
        cin>>subTree[i];
    }
    idx = -1;
    Node* subRoot = buildTree(subTree);
    cout<<isSubTree(root,subRoot)<<endl;
    return 0;
}