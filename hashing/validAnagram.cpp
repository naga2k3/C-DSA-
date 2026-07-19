#include <bits/stdc++.h>
using namespace std;

bool validAnagram(string s1 ,string s2){
    if(s1.size()  != s2.size())return false;
    unordered_map<char,int>m;
    for(char c : s1){
        m[c]++;
    }
    for(char c : s2){
        if(m.count(c)){
            m[c]--;
            if(m[c] == 0) m.erase(c);
        }else{
            return false;
        }
    }
    return true;
}

int main(){
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    cout<<validAnagram(s1,s2);
    return 0;  
}