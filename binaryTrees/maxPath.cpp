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
void levelOrder(Node* root){
    if(root == NULL) return;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        if(curr == NULL){ 
            cout<<endl;     
            if(q.empty()) break;
            q.push(NULL);
        }else{
            cout<<curr->data<<" ";
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        } 
    }
}
int height(Node* root,int &maxVal){
    if(root == NULL) return 0;
    int LH = max(0,height(root->left,maxVal));
    int RH = max(0,height(root->right,maxVal));
    maxVal = max(maxVal , LH+RH+root->data);
    return root->data+max(LH,RH);
}
int maxPathSum(Node* root){
    int maxVal = INT_MIN;
    height(root,maxVal);
    return maxVal;
}
int main(){
    int n;
    cin>>n;
    vector<int>tree(n);
    for(int i=0;i<n;i++){
        cin>>tree[i];
    }
    Node* root = buildTree(tree);
    levelOrder(root);
    cout<<maxPathSum(root);
    return 0;
}