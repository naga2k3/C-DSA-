#include <bits/stdc++.h>
using namespace std;

void countingSort(int a[],int n){
    int freq[10000];
    int minArr =a[0];
    int maxArr = a[0];
    for(int i=0;i<n;i++){
        freq[a[i]]++;
        minArr = min(minArr , a[i]);
        maxArr = max(maxArr , a[i]);
    }
    int j=0;
    for(int i=minArr;i<=maxArr;i++){
        while(freq[i] > 0){
            a[j++] = i;
            freq[i]--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    countingSort(a,n);
}