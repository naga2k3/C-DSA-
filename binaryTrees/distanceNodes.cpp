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
bool pathOfTree(Node* root,vector<int>&path,int n){
    if(root == NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data == n){
        return true;
    }
    bool left = pathOfTree(root->left,path,n);
    bool right = pathOfTree(root->right,path,n);
    if(left || right){
        return true;
    }
    path.pop_back();
    return false;
}
int distanceNodes(Node* root , int n1 ,int n2){
    vector<int>path1;
    vector<int>path2;
    pathOfTree(root->left,path1, n1);
    pathOfTree(root->right,path2,n2);
    return path1.size()+path2.size();
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
    cout<<distanceNodes(root,n1,n2);
    return 0;
}