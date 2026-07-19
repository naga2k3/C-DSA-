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
    int countNodes(Node* root){
        int count = 1;
        for(auto it : root->children){
            count += countNodes(it.second);
        }
        return count;
    }
};


void countUniquePrefix(string ans){
    Trie trie;
    for(int i=0;i<ans.size();i++){
        string a = ans.substr(i);
        trie.insert(a);
    }
    cout<<trie.countNodes(trie.root);
}
int main(){
    countUniquePrefix("abc");
    return 0;
}