#include <bits/stdc++.h>
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
bool isPalin(string str){
    int n = str.size();
    for(int i=0;i<n/1;i++){
        if(str[i] != str[n-i-1]) return false;
    }
    return true;
}
bool isPalindrome(Node* head){
    string str="";
    while(head){
        str += head->data;
        head= head->next;
    }
    return isPalin(str);
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
    cout<<isPalindrome(ll.head);
}