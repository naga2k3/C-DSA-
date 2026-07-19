#include <bits/stdc++.h>
using namespace std;

class Heap{
    vector<int>vec;
public:
    void push(int val){
        vec.push_back(val);
        int x = vec.size()-1;
        int parentIdx = (x-1)/2;
        while(parentIdx >=0 && vec[parentIdx] < vec[x]){
            swap(vec[parentIdx] , vec[x]);
            x = parentIdx;
            parentIdx = (x-1)/2;
        }
    }
    void heapify(int idx){
        if(idx > vec.size())return;
        int l = 2*idx+1;
        int r = 2*idx+2;
        int maxIdx = idx;
        if(l < vec.size() && vec[l] > vec[maxIdx]){
            maxIdx = l;
        }
        if(r < vec.size() && vec[r] > vec[maxIdx]){
            maxIdx = r;
        }
        swap(vec[idx] , vec[maxIdx]);
        if(maxIdx != idx){
            heapify(maxIdx);
        }
    }
    void pop(){
        swap(vec[0] , vec[vec.size()-1]);
        vec.pop_back();
        heapify(0);
    }
    int top(){
        return vec[0];
    }
    bool isEmpty(){
        return vec.size() == 0;
    }
};

int main(){
    Heap heap;
    heap.push(1);
    heap.push(50);
    heap.push(100);
    heap.push(35);
    while(!heap.isEmpty()){
        cout<<heap.top()<<endl;
        heap.pop();
    }
    return 0;
}