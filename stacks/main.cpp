#include <bits/stdc++.h>
using namespace std;

template<class T>
class Stack{
vector<T>vec;
public:
    bool isEmpty(){
        return vec.size() == 0;
    }
    void push(T val){
        vec.push_back(val);
    }
    void pop(){
        if(isEmpty()){
            cout<<"stack is Empty\n";
            return;
        }
        vec.pop_back();
    }
    T top(){
        return vec[vec.size()-1];
    }
};

int main(){
    Stack<string>s;
    s.push("TE AMO");
    s.push("MUCHO");
    s.push("ESMY");
    s.push("NAGA");
    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}