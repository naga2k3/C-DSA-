#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
class Queue{
    Node* head;
    Node* tail;
public:
    Queue(){
        head=tail=NULL;
    }
    bool empty(){
        return head == NULL;
    }
    void push(int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop(){
        if(empty()){
            cout<<"Queue is Empty";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    int top(){
        if(empty()) return -1;
        return head->data;
    }
};
int main(){
    Queue q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.pop();
    while(!q1.empty()){
        cout<<q1.top()<<" ";
        q1.pop();
    }
    return 0;
}