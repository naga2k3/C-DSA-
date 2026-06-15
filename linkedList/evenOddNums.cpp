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
    List ansEven;
    List ansOdd;
    while(head){
        int x = head->data;
        if(x%2 == 0){
            ansEven.push_back(x);
        }else{
            ansOdd.push_back(x);
        }
        head = head->next;
    }
    if(ansEven.head == NULL){
        return ansOdd.head;
    }
    Node* temp = ansEven.head;
    while(temp && temp->next){
        temp = temp->next;
    }
    temp -> next = ansOdd.head;
    return ansEven.head;
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