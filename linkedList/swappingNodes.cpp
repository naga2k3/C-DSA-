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
Node* swapNodes(Node* head,int x,int y){
    if(x == y) return head;
    Node* currX = head;
    Node* prevX = NULL;
    Node* prevY = NULL;
    while(currX && currX->data != x){
        prevX  = currX;
        currX = currX->next;
    }
    Node* currY = head;
    while(currY && currY->data != y){
        prevY = currY;
        currY = currY->next;
    }
    if(!currX || !currY) return head;
    Node* nextX = currX->next;
    Node* nextY = currY->next;
    if(prevX) prevX->next = currY;
    else head = currY;
    if(prevY) prevY->next = currX;
    else head = currX;
    currY ->next = nextX;
    currX -> next = nextY;
    return head;
}
int main(){
    List ll;
    int size,x,y;
    cin>>size>>x>>y;
    for(int i=0;i<size;i++){
        int val;
        cin>>val;
        ll.push_back(val);
    }
    ll.printList(ll.head);
    ll.head = swapNodes(ll.head,x,y);
    ll.printList(ll.head);
}