#include <bits/stdc++.h>
using namespace std;
string simplifyPath(string path){
    stack<string>st;
    string curr="";
    for(int i=0;i<=path.size();i++){
        if(i == path.size() || path[i] == '/'){
            if(curr == "" || curr == "."){

            }
            else if(curr==".."){
                if(!st.empty()) st.pop();
            }else{
                st.push(curr);
            }
            curr="";
        }else{
            curr += path[i];
        }
    }
    string ans="";
    while(!st.empty()){
        ans = "/"+st.top()+ans;
        st.pop();
    }
    return ans.empty() ? "/" : ans;
}
int main(){
    string str;
    getline(cin,str);
    cout<<simplifyPath(str);
    return 0;
}