#include <bits/stdc++.h>
using namespace std;
// void spiralMatrix(int a[][] , int n , int m){
//     int srow=0 , scol=0 , erow = n-1 , ecol = m-1;
//     while(scol <= ecol && srow <= erow){
//         for(int i = srow ; i <= ecol; i++ ){
//             cout<<a[srow][i]<<" ";
//         }
//         srow++;
//         for(int i = srow ; i <= erow;i++){
//             cout<<a[i][ecol]<<" ";
//         }
//         ecol--;
//         for(int i = ecol ; i <= scol ;i--){
//             cout<<a[erow][i];
//         }
//         erow--;
//         for(int i = erow ; i <= srow ; i--){
//             cout<<a[i][scol];
//         }
//         scol++;
//     }
// }
int main(){
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }    
    int srow=0 , scol=0 , erow = n-1 , ecol = m-1;
    while(scol <= ecol && srow <= erow){
        for(int i = scol ; i <= ecol; i++ ){
            cout<<a[srow][i]<<" ";
        }
        srow++;
        for(int i = srow ; i <= erow;i++){
            cout<<a[i][ecol]<<" ";
        }
        ecol--;
        for(int i = ecol ; i >= scol ;i--){
            if(srow == erow){
                break;
            }
            cout<<a[erow][i]<<" ";
        }
        erow--;
        for(int i = erow ; i >= srow ; i--){
            if(scol == ecol){
                break;
            }
            cout<<a[i][scol]<<" ";
        }
        scol++;
    }
}