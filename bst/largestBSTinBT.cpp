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
class Info{
public:
    bool isBST;
    int minVal;
    int maxVal;
    int size;
    Info(bool isBST,int minVal,int maxVal,int size){
        this->isBST = isBST;
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->size = size;
    }
};  
static int maxSize;
static TreeNode* curr;
Info* largestBST(TreeNode* root){
    if(root == nullptr){
        return new Info(true,INT_MAX,INT_MIN,0);
    }
    Info* leftInfo = largestBST(root->left);
    Info* rightInfo = largestBST(root->right);
    int currMax = max(root->val,max(leftInfo->maxVal , rightInfo->maxVal));
    int currMin = min(root->val,min(leftInfo->minVal , rightInfo->minVal));
    int currSize = leftInfo->size + rightInfo->size +1;
    if(leftInfo->isBST && rightInfo->isBST
        &&leftInfo->maxVal < root->val && root->val < rightInfo->minVal){
            if(currSize > maxSize){
                maxSize = currSize;
                curr = root;
            }
            return new Info(true,currMin,currMax,currSize);
        }
        return new Info(false,currMin,currMax,currSize);
    }
int main(){
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(20);
    root->right = new TreeNode(60);
    root->right->left= new TreeNode(45);
    root->right->right= new TreeNode(70);
    root->right->right->left = new TreeNode(65);
    root->right->right->right = new TreeNode(80);
    largestBST(root);
    cout<<maxSize<<" "<<curr;
    return 0;
}