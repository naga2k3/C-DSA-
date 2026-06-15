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
    int diagonalSum =0;;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i == j){
                diagonalSum += a[i][j];
            }
            else if(j == n-i-1){
                diagonalSum += a[i][j];
            }
        }
    }
    cout<<"DiagonalSum: "<<diagonalSum ;
}