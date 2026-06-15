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
Node* splitAtMid(Node* head){
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;
    while(fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(prev != NULL){
        prev -> next = NULL;
    }
    return slow;
}
Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    while(curr){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node* merge(Node* left , Node* right){
    List ans;
    Node*i = left;
    Node*j = right;
    while(i && j){
        ans.push_back(i->data);
        ans.push_back(j->data);
        i = i->next;
        j = j->next;
    }
    while(j){
        ans.push_back(j->data);
        j=j->next;
    }
    return ans.head;
}
Node* zigzag(Node* head){
    Node* left = head;
    Node* rightHead = splitAtMid(head);
    Node* right = reverse(rightHead);
    //return merge(left , reverse(right));
    Node* tail = right;
    while(left && right){
        Node* nextLeft = left->next;
        Node* nextRight = right->next;
        left->next = right;
        right->next = nextLeft;
        tail = right;
        left = nextLeft;
        right = nextRight;
    }
    if(right){
        tail->next = right;
    }
    return head;
}
int main(){
    List ll;
    ll.push_front(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.printList(ll.head);
    ll.head = zigzag(ll.head);
    ll.printList(ll.head);
}