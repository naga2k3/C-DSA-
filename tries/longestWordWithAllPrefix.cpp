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

void longestWordWithAllPrefix(Node* root,string &ans,string temp){
    for(auto it : root->children){
        if(it.second->endOfWord == true){
            temp += it.first;
            if( (ans.size() < temp.size()) || (temp.size() == ans.size() && temp < ans) ){
                ans = temp;
            }
            longestWordWithAllPrefix(it.second,ans,temp);
            temp = temp.substr(0,temp.size()-1);
        }
    }
}
int main(){
    vector<string>dict={"a","banana","app","appl","ap","appla","apple"};
    Trie trie;
    for(string s : dict){
        trie.insert(s);
    }
    string ans;
    longestWordWithAllPrefix(trie.root,ans,"");
    cout<<ans;
    return 0;
}