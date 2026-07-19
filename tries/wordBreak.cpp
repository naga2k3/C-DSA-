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
            if(temp->children[ch] == 0)return false;
            else{
                temp = temp->children[ch];
            }
        }
        return temp->endOfWord;
    }
};
bool helper(Trie &trie, string key){
    if(key.size() == 0)return true;
    for(int i=0;i<key.size();i++){
        string first = key.substr(0,i+1);
        string second = key.substr(i+1);
        if(trie.search(first) && helper(trie,second)){
            return true;
        }
    }
    return false;
}
bool wordBreak(vector<string>dict , string key){
    Trie trie;
    for(auto it : dict){
        trie.insert(it);
    }
    return helper(trie,key);
}
int main(){
    vector<string>dict={"i","like","sam","samsung","mobile","ice"};
    cout<<wordBreak(dict,"ilikesamsung");
    return 0;
}