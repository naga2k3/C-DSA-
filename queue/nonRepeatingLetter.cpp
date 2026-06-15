#include <bits/stdc++.h>
using namespace std;
void nonRepeatingLetter(string s){
    queue<char>q;
    int freq[26] = {0};
    for(char ch : s){
        int val = ch - 'a';
        freq[val]++;
        q.push(ch);
        while(!q.empty() && freq[q.front()-'a'] > 1){
            q.pop();
        }
        if(q.empty()) cout<<"-1";
        else cout<<q.front();
    }
}
int main(){
    string s;
    getline(cin,s);
    nonRepeatingLetter(s);
    return 0;
}