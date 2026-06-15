#include <bits/stdc++.h>
using namespace std;
void interLeaveQueue(queue<int> &q,int n){
    queue<int>help;
    for(int i=0;i<n/2;i++){
        help.push(q.front());
        q.pop();
    }
    while(!help.empty()){
        q.push(help.front());
        help.pop();
        q.push(q.front());
        q.pop();
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
    interLeaveQueue(q,n);
    for(int i=0;i<n;i++){
        cout<<q.front()<<" ";
        q.pop();
    }
}