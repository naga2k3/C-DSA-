#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    unordered_map<char,Node*>children;
    bool endOfWord;
    Node(){
        endOfWord = false;
    }
};
class Trie{
public:
    Node* root;
    Trie(){
        root = new Node();
    }
    void insert(string key){
        Node* temp = root;
        for(char ch : key){
            if(temp->children[ch] == 0){
                temp->children[ch] = new Node();
            }
            temp = temp->children[ch];
        }
        temp->endOfWord = true;
    }
    bool search(string key){
        Node* temp = root;
        for(char ch : key){
            if(temp->children[ch] == 0)return false;
            else{
                temp = temp->children[ch];
            }
        }
        return temp->endOfWord;
    }
};

bool startsWith(Trie &trie , string key){
    Node* temp = trie.root;
    for(char ch : key){
        if(temp->children.count(ch) == 1){
            temp = temp->children[ch];
        }else{
            return false;
        }
    }
    return true;
}

int main(){
    vector<string>words={"apple","app","mango","man","woman"};
    Trie trie;
    for(auto it : words){
        trie.insert(it);
    }
    cout<<startsWith(trie,"apo");
}