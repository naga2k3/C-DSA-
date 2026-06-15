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
    for(int i=0;i<n;i++){
        for(int j=i+1;j<m;j++){
            swap(a[i][j] , a[j][i]);
        }
    }
    cout<<"After Transpose: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int k=0;k<n;k++){
        int i=0 , j=m-1;
        while(i<=j){
            swap(a[k][i++],a[k][j--]);
        }
    }
    cout<<"After 90 Degrees (Clock Wise):"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}