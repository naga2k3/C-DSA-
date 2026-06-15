#include <bits/stdc++.h>
using namespace std;
string reverseString(string str){
    stack<char>s;
    string ans;
    for(int i=0;i<str.size();i++){
        s.push(str[i]);
    }
    while(!s.empty()){
        ans += s.top();
        s.pop();
    }
    return ans;
}
int main(){
    string str;
    getline(cin,str);
    cout<<reverseString(str);
    return 0;
}