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
Node* buildTree(vector<int>nodes){
    idx++;
    if(nodes[idx] == -1){
        return NULL;
    }
    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);
    return currNode;
}
int height(Node* root){
    if(root == NULL) return 0;
    int leftHt = height(root->left);
    int rightHt = height(root->right);
    int currHt = max(leftHt , rightHt) + 1;
    return currHt;
}
int count(Node* root){
    if(root == NULL) return 0;
    int leftCount = count(root->left);
    int rightCount = count(root->right);
    int currCount = leftCount + rightCount + 1;
    return currCount;
}
int sum(Node* root){
    if(root == NULL) return 0;
    int leftSum = sum(root->left);
    int rightSum = sum(root->right);
    int currSum = leftSum + rightSum + root->data;
    return currSum;

}
int main(){
    int n;
    cin>>n;
    vector<int>tree(n);
    for(int i=0;i<n;i++){
        cin>>tree[i];
    }
    Node* root = buildTree(tree);
    cout<<height(root)<<endl;
    cout<<count(root)<<endl;
    cout<<sum(root);
    return 0;
}