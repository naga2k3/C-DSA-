#include <bits/stdc++.h>
using namespace std;
void printStack(stack<int>s){
    while(!s.empty()){
        cout<<s.top()<<"";
        s.pop();
    }
    cout<<endl;
    return;
}
void pushAtBottom(stack<int>&s , int val){
    if(s.empty()){
        s.push(val);
        return;
    }
    int temp = s.top();
    s.pop();
    pushAtBottom(s,val);
    s.push(temp);
}
void reverseStack(stack<int> &s){
    if(s.empty()){
        return;
    }
    int temp = s.top();
    s.pop();
    reverseStack(s);
    pushAtBottom(s,temp);
}
int main(){
    stack<int>s;
    s.push(3);
    s.push(2);
    s.push(1);
    printStack(s);
    reverseStack(s);
    printStack(s);
    return 0;
}