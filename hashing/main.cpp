#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    string key;
    int val;
    Node* next;
    Node(string key,int val){
        this->key = key;
        this->val = val;
        next = NULL;
    }
    ~Node(){
        if(next != NULL){
            delete next;
        }
    }
};

class HashTable{
    int totalSize;
    int currSize;
    Node**table;
    int hashFunction(string key){
        int idx=0;
        for(int i=0;i<key.size();i++){
            idx = idx + (key[i] * key[i])%totalSize;
        }
        return idx % totalSize;
    }
    void rehash(){
        Node** oldTable = table;
        int oldSize = totalSize;
        totalSize *= 2;
        currSize = 0;
        table = new Node*[totalSize];
        for(int i=0;i<totalSize;i++){
            table[i] = NULL;
        }
        //Copies old Values
        for(int i=0;i<oldSize;i++){
            Node* temp = oldTable[i];
            while(temp != NULL){
                insert(temp->key,temp->val);
                temp = temp->next;
            }
            if(oldTable[i] != NULL){
                delete oldTable[i];
            } 
        }
        delete[] oldTable;
    }
public:
    HashTable(int size=5){
        totalSize = size;
        currSize = 0;
        table = new Node*[totalSize];
        for(int i=0;i<totalSize;i++){
            table[i] = NULL;
        }
    }
    void insert(string key,int val){
        int idx = hashFunction(key);
        Node* newNode = new Node(key,val);
        newNode->next = table[idx];
        table[idx] = newNode;
        currSize++;
        double lambda = currSize/(double)totalSize;
        if(lambda > 1){
            rehash();
        }
    }
    bool exist(string key){
        int idx = hashFunction(key);
        Node* temp = table[idx];
        while(temp != NULL){
            if(temp->key == key) return true;
            temp = temp->next;
        }
        return false;
    }
    int search(string key){
        int idx = hashFunction(key);
        Node* temp = table[idx];
        while(temp != NULL){
            if(temp->key == key){
                return temp->val;
            }
            temp = temp->next;
        }
        return -1;
    }
    void remove(string key){
        int idx = hashFunction(key);
        Node* temp = table[idx];
        Node* prev  = temp;
        while(temp != NULL){
            if(temp->key == key){
                if(prev == temp){
                    table[idx]  = temp->next;
                }else{
                    prev->next  = temp->next;
                }
            }
            prev = temp;
            temp = temp->next;
        }
    }
    void print(){
        for(int i=0;i<totalSize;i++){
            cout<<"idx "<<i<<"->";
            Node* temp = table[i];
            while(temp != NULL){
                cout<<"("<<temp->key<<","<<temp->val<<")";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
};

int main(){
    HashTable ht(5);
    ht.insert("India",150);
    ht.insert("China",151);
    ht.insert("USA",50);
    ht.insert("Russia",30);
    ht.insert("Canada",45);
    ht.insert("Belize",15);
    ht.insert("Japan",10);
    ht.print();
    cout<<endl;
    ht.remove("Russia");
    ht.print();
    return 0;
}