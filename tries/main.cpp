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
    Node* root;
public:
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
            if(temp->children[ch] == nullptr)return false;
            else{
                temp = temp->children[ch];
            }
        }
        return temp->endOfWord;
    }
};

int main(){
    vector<string>a = {"the","a","there","their","any","thee"};
    Trie trie;
    for(int i=0;i<a.size();i++){
        trie.insert(a[i]);
    }
    cout<<trie.search("ther");
    return 0;
}