#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int key;
    cin>>key;

    // Using BruteForce
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(key == a[i][j]){
    //             cout<<i<<" "<<j;
    //         }
    //     }
    // }

    // Using Binary search
    // for(int i=0;i<n;i++){
    //     int start = 0;
    //     int end = m-1;
    //     while(start <= end){
    //         int mid = (start+end)/2;
    //         if(key == a[i][mid]){
    //             cout<<i<<mid;
    //             return 0;
    //         }
    //         else if(key> a[i][mid]){
    //             start = mid+1;
    //         }
    //         else{
    //             end = mid-1;
    //         }
    //     }
    // }
    // cout<< " Not Found " ;

    // Staircase Search(right top)
    int i=0,j=m-1;
    while(i<n && j>=0){
        int start = a[i][j];
        if(start == key){
            cout<<i<<j;
            return 0;
        }
        else if(key > start){
            i++;
        }
        else{
            j--;
        }
    }

    // Staircase Search(left bottom)
    int i=n-1,j=0;
    while(i>=0 && j<m){
        int start = a[i][j];
        if(start == key){
            cout<<i<<j;
            return 0;
        }
        else if(key > start){
            j++;
        }
        else{
            i--;
        }
    }
} 