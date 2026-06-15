#include <bits/stdc++.h>
using namespace std;

bool isValid(string str){
    stack<char>s;
    for(int i=0;i<str.size();i++){
        char ch = str[i];
        if(ch != ')'){
            s.push(ch);
        }else{
            if(s.top() == '(') return true;
            else{
                while(s.top() != '('){
                    s.pop();
                }
                s.pop();
            }
        }
    }
    return false;
}

int main(){
    string str;
    getline(cin , str);
    cout<<isValid(str);
    return 0;
}