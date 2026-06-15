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
TreeNode* buildBSTFromSorted(int arr[],int st , int end){
    if(st>end) return nullptr;
    int mid = st+(end-st)/2;
    TreeNode* curr = new TreeNode(arr[mid]);
    curr->left = buildBSTFromSorted(arr,st,mid-1);
    curr->right = buildBSTFromSorted(arr,mid+1,end);
    return curr;
}
void preOrder(TreeNode* root){
    if(root == nullptr) return;
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    TreeNode* root = buildBSTFromSorted(arr,0,n-1);
    preOrder(root);
    return 0;
}