#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int>& a){
    int candidate = 0;
    int count =0;
    for(int n : a){
        if(candidate == 0){
            candidate = n;
        }
        if(candidate == n) count++;
        else count--;
    }
    return candidate;
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<majorityElement(a);
}