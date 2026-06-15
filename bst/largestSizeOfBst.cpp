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
int height(TreeNode* root){
    if(root == NULL) return 0;
    int leftHt = height(root->left);
    int rightHt = height(root->right);
    int currHt = max(leftHt , rightHt) + 1;
    return currHt;
}
bool validateBst(TreeNode* root,TreeNode* minVal , TreeNode* maxVal){
    if(root == NULL) return true;
    if(minVal != NULL && minVal->val > root->val){
        return false;
    }
    if(maxVal != NULL && root->val > maxVal->val){
        return false;
    }
    return validateBst(root->left,minVal,root) && validateBst(root->right,root,maxVal);
}
int largestSizeOfBst(TreeNode* root,int maxHeight){
    if(root == nullptr) return 0;
    if(validateBst(root,nullptr,nullptr)){
        int ht = height(root);
        maxHeight = max(ht, maxHeight);
    }
    return maxHeight;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    TreeNode* root = buildBSTFromSorted(arr,0,n-1);
    cout<<largestSizeOfBst(root,0);
    return 0;
}