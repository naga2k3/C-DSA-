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
int maxHeight(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = maxHeight(root->left);
    int rightHeight = maxHeight(root->right);
    int currHeight = max(leftHeight ,rightHeight) + 1;
    return currHeight;
}
int diameter(Node* root){
    if(root == NULL) return 0;
    int rootDiameter = maxHeight(root->left) + maxHeight(root->right) + 1;
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);
    return max(rootDiameter , max(leftDiameter , rightDiameter));
}
int main(){
    int n;
    cin>>n;
    vector<int>tree(n);
    for(int i=0;i<n;i++){
        cin>>tree[i];
    }
    Node* root = buildTree(tree);
    cout<<diameter(root);
    return 0;
}