#include <bits/stdc++.h>
using namespace std;
class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        left = right = nullptr;
    }
};
TreeNode* buildBSTFromSorted(vector<int> &arr,int st , int end){
    if(st>end) return nullptr;
    int mid = st+(end-st)/2;
    TreeNode* curr = new TreeNode(arr[mid]);
    curr->left = buildBSTFromSorted(arr,st,mid-1);
    curr->right = buildBSTFromSorted(arr,mid+1,end);
    return curr;
}
void inOrder(TreeNode* root,vector<int> &arr){
    if(root == nullptr) return;
    inOrder(root->left,arr);
    arr.push_back(root->val);
    inOrder(root->right,arr);
}
void preOrder(TreeNode* root){
    if(root == nullptr) return;
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
int main(){
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->right->right= new TreeNode(8);
    root->right->right->right = new TreeNode(9);
    vector<int>arr;
    inOrder(root,arr);
    int n = arr.size();
    preOrder(root);
    cout<<endl;
    root = buildBSTFromSorted(arr,0,n-1);
    preOrder(root);
    return 0;
}