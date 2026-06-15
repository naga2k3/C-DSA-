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
Node* mNodesN(Node* head , int m , int n){
    Node* temp = head;
    while(temp){
        for(int i=0;i<m-1;i++){
            temp = temp->next;
        }
        if(!temp){
            return head;
        }
        Node* curr = temp;
        for(int i=0;i<n && curr;i++){
            curr = curr->next;
        }
        temp->next = curr ? curr->next : NULL;
        temp = temp->next;  
    }
    return head;
}
int main(){
    List ll;
    int m,n;
    cin>>n>>m;
    int size;
    cin>>size;
    for(int i=0;i<size;i++){
        int x;
        cin>>x;
        ll.push_back(x);
    }
    ll.printList(ll.head);
    ll.head = mNodesN(ll.head,m,n);
    ll.printList(ll.head);
    return 0;
}