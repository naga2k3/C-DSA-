#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    unordered_map<char,Node*>children;
    bool endOfWord;
    int freq;
    Node(){
        endOfWord = false;
    }
};
class Trie{
public:
    Node* root;
    Trie(){
        root = new Node();
        root->freq = -1;
    }
    void insert(string key){
        Node* temp = root;
        for(char ch : key){
            if(temp->children[ch] == 0){
                temp->children[ch] = new Node();
                temp->children[ch]->freq= 1;
            }else{
                temp->children[ch]->freq++;
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
    string getPrefix(string key){
        Node* temp = root;
        string ans;
        for(char ch : key){
            temp = temp->children[ch];
            ans += ch;
            if(temp->freq == 1){
                return ans;
            }
        }
        return ans;
    }
};

void prefixProblem(vector<string>&words,vector<string>&ans){
    Trie trie;
    for(auto it : words){
        trie.insert(it);
    }
    for(string key : words){
        ans.push_back(trie.getPrefix(key));
    }
}
int main(){
    vector<string>words = {"zebra","zebro","dog","duck","dove"};
    vector<string>ans;
    prefixProblem(words,ans);
    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0;
}