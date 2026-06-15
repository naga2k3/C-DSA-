#include <bits/stdc++.h>
using namespace std;
string enCode(string str){
    stack<int>st;
    stack<string>st1;
    string ans = "";
    int n = 0;
    for(char c : str){
        if(isdigit(c)){
            n = n*10+(c-'0');
        }else if(c == '['){
            st.push(n);
            n=0;
            st1.push(ans);
            ans="";
        }else if(c == ']'){
            int k = st.top();
            st.pop();
            string temp = ans;
            ans = st1.top();
            st1.pop();
            while(k-- > 0){
                ans += temp;
            }
        }else{
            ans += c;
        }
    }
    return ans;
}
int main(){
    string str;
    getline(cin,str);
    cout<<enCode(str);
}