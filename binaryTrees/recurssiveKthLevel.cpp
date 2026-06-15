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
void recurssiveKthLevel(Node* root , int k,int currLevel){
    if(root == NULL) return;
    if(currLevel == k){
        cout<<root->data<<" ";
        return;
    }
    recurssiveKthLevel(root->left,k,currLevel+1);
    recurssiveKthLevel(root->right,k,currLevel+1);
}
int main(){
    int n;
    cin>>n;
    vector<int>tree(n);
    for(int i=0;i<n;i++){
        cin>>tree[i];
    }
    Node* root = buildTree(tree);
    int k;
    cin>>k;
    recurssiveKthLevel(root,k,1);
    return 0;
}