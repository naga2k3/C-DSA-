#include <bits/stdc++.h>
using namespace std;
class Queue{
    int *arr;
    int capacity;
    int currSize;
    int f,r;
public:
    Queue(int capacity){
        this->capacity = capacity;
        arr = new int[capacity];
        currSize = 0;
        f=0,r=-1;
    }
    bool empty(){
        return currSize == 0;
    }
    void push(int data){
        if(capacity == currSize){
            cout<<"Queue is full \n";
            return;
        }
        r = (r+1)%capacity;
        arr[r] = data;
        currSize++;
    }
    void pop(){
        if(empty()){
            cout<<"Queue is Empty \n";
            return;
        }
        f = (f+1)%capacity;
        currSize--;
    }
    int front(){
        if(empty()){
            cout<<"Queue is Empty \n";
            return -1;
        }
        return arr[f];
    }
};
int main(){
    Queue q(4);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front();
}