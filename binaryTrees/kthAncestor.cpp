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
bool findPath(Node* root,vector<int>&path,int n){
    if(root == NULL) return false;
    path.push_back(root->data);
    if(root->data == n){
        return true;
    }
    bool left = findPath(root->left,path,n);
    bool right = findPath(root->right,path,n);
    if(left||right){
        return true;
    }
    path.pop_back();
    return false;
}
int kthAncestor(Node* root,int n,int k){
    vector<int>path;
    findPath(root,path,n);
    for(int i=0;i<path.size();i++){
        if(path[i] == n){
            return path[i-k];
        }
    }
    return -1;
}
int kthAncestor1(Node* root,int n,int k){
    if(root == NULL) return -1;
    if(root->data == n) return 0;
    int left = kthAncestor1(root->left,n,k);
    int right = kthAncestor1(root->right,n,k);
    if(left == -1 && right == -1){
        return -1;
    }
    int validVal = left == -1 ? right : left;
    if(validVal+1 == k){
        return root->data;
    }
    return validVal+1;
}
int main(){
    int n;
    cin>>n;
    vector<int>tree(n);
    for(int i=0;i<n;i++){
        cin>>tree[i];
    }
    Node* root = buildTree(tree);
    int n1,k;
    cin>>n1>>k; 
    cout<<kthAncestor1(root,n1,k);
    return 0;
}