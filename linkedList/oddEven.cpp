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
Node* oddEven(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* odd = head;
    Node* even = head->next;
    Node* startEven = head->next;
    while(even && even->next){
        odd->next = even->next;
        even->next = odd->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = startEven;
    return head;
}
int main(){
    List ll;
    int size;
    cin>>size;
    for(int i=0;i<size;i++){
        int val;
        cin>>val;
        ll.push_back(val);
    }
    ll.printList(ll.head);
    ll.head = oddEven(ll.head);
    ll.printList(ll.head);
}