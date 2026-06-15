#include <bits/stdc++.h>
using namespace std;
void reverse(queue<int>&q){
    stack<int>s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}
int main(){
    queue<int>q;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        q.push(a);
    }
    reverse(q);
    for(int i=0;i<n;i++){
        cout<<q.front()<<" ";
        q.pop();
    }
}