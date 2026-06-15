#include <bits/stdc++.h>
#include <list>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
class List{
public:
    Node *head = NULL;
    Node *tail = NULL;
    List(){
        head = NULL;
        tail = NULL;
    }
    void push_front(int val){
        Node * newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode -> next = head;
            head = newNode;
        }
    }
    void push_back(int val){
        Node *newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail -> next = newNode;
            tail = newNode;
        }
    }
    void printList(Node* head){
        Node * temp = head;
        while(temp != NULL){
            cout << temp -> data<<"->";
            temp = temp -> next;            
        }
        cout<<"NULL\n";
    }
};
Node* merge(Node* List1 ,Node* List2){
    Node* merged = new Node(-1);
    Node* mptr = merged;
    Node* left = List1;
    Node* right = List2;
    while(left && right){
        if(left->data <= right->data){
            mptr->next = left;
            mptr = mptr->next;
            left = left->next;
        }else{
            mptr->next = right;
            mptr = mptr->next;
            right = right->next;
        }
    }
    while(left){
        mptr->next = left;
        mptr = mptr->next;
        left = left->next;
    }
    while(right){
        mptr->next = right;
        mptr = mptr->next;
        right = right->next;            
    }
    return merged->next;
}
Node* mergeKLists(vector<Node*>& lists){
    if(lists.size() == 0){
        return NULL;
    }
    if(lists.size() == 1){
        return lists[0];
    }
    Node* head = lists[0];
    for(int i=1;i<lists.size();i++){
        head = merge(head , lists[i]);
    }
    return head;
}
int main(){
    List ans;
    int k;
    cin>>k;
    vector<Node*> lists;
    for(int i=0;i<k;i++){
        int size;
        cin>>size;
        List ll;
        for(int j=0;j<size;j++){
            int val;
            cin>>val;
            ll.push_back(val);
        }
        lists.push_back(ll.head);
    }
    ans.head= mergeKLists(lists);
    ans.printList(ans.head);
}