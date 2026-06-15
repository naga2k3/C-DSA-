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
    ~Node(){
        if(next != NULL){
            delete next;
            next = NULL;
        }
    }
};
class List{
    Node *head = NULL;
    Node *tail = NULL;
public:
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
    void printList(){
        Node * temp = head;
        while(temp != NULL){
            cout << temp -> data<<"->";
            temp = temp -> next;            
        }
        cout<<"NULL\n";
    }
    void insert(int val , int pos){
        Node *newNode = new Node(val);
        Node *temp = head;
        for(int i=0;i<pos-1;i++){
            temp = temp -> next;
        }
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
    void pop_front(){
        Node*temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    void pop_back(){
        Node *temp = head;
        while(temp -> next -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = NULL;
        delete tail;
        tail = temp;
    }
    ~List(){
        if(head != NULL){
            delete head;
            head = NULL;
        }
    }
    int searchItr(int key){
        Node *temp = head;
        int idx = 0;
        while(temp != NULL){
            if(temp -> data == key){
                return idx;
            }
            idx++;
            temp = temp -> next;
        }
        return -1;
    }
    int helper(Node *temp ,int key){
        if(temp == NULL){
            return -1;
        }
        if(temp -> data == key){
            return 0;
        }
        int idx = helper(temp -> next , key);
        if(idx == -1){
            return -1;
        }
        return idx+1;
    }
    int searchRec(int key){
        return helper(head,key);
    }
    void reverse(){
        Node *curr = head;
        Node *prev = NULL;
        tail = head;
        while(curr != NULL){
            Node *next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    void removeNode(int n){
        int size =0;
        Node *temp = head;
        while(temp != NULL){
            temp = temp -> next;
            size++;
        }
        if(n == size){
            Node* del = head;
            head = head->next;
            del->next = NULL;
            delete del;
            return;
        }
        Node *curr = head;
        Node *prev = NULL;
        for(int i=0;i<size-n;i++){    
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
};

int main(){
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.printList();
    //cout<<ll.searchItr(2)<<endl;
    //cout<<ll.searchRec(2)<<endl;
    //ll.reverse();
    ll.removeNode(3);
    ll.printList();
    return 0;
}