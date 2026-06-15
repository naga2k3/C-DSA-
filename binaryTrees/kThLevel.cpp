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
void kThLevel(Node* root , int k){
    if(root == NULL) return;
    if(k == 1){
        cout << root->data << " ";
        return;
    }
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    int level = 1;
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        if(curr == NULL){
            level++;
            if(q.empty()){
                break;
            }
            q.push(NULL);
        }else{
            if(level == k){
                cout<<curr->data<<" ";
            }
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
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
    kThLevel(root,k);
    return 0;
}