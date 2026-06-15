#include <bits/stdc++.h>
using namespace std;
int getGridWays(int row,int col,int n ,int m,string ans){
    if(row == n-1 && col == m-1){
        cout<<ans<<"\n";
        return 1;
    }
    if(row >= n || col >= m){
        return 0;
    }
    int v1 = getGridWays(row+1,col,n,m,ans+"D");
    int v2 = getGridWays(row,col+1,n,m,ans+"R");
    return v1+v2;
}
int main(){
    int n,m;
    cin>>n>>m;
    int row,col;
    cin>>row>>col;
    cout<<getGridWays(row,col,n,m,"");
}