#include <bits/stdc++.h>
using namespace std;

int activitySelection(int start[] , int end[],int n){
    int count =1;
    int currEnd = end[0];
    for(int i=1;i<n;i++){
        if(currEnd <= start[i]){
            count++;
            currEnd = end[i];
        }
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    int start[n];
    int end[n];
    for(int i=0;i<n;i++){
        cin>>start[i];
    }
    for(int i=0;i<n;i++){
        cin>>end[i];
    }
    cout<<activitySelection(start,end,n);
    return 0;
}