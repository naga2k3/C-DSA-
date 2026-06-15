#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin>>num;
    int b[num];
    for(int i=0;i<num;i++){
        cin>>b[i];
    }
    int n,m;
    cin>>n>>m;
    int a[n][m];
    int i=0;
    for(int k=0;k<n;k++){
        for(int j=0;j<m;j++){
            a[k][j] = b[i++];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}