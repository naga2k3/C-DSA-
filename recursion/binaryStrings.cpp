#include <bits/stdc++.h>
using namespace std;
void binaryStrings(int n,int lastplace , string ans){
    if(n == 0){
        cout<<ans<<endl;
        return;
    }
    if(lastplace != 1){
        binaryStrings(n-1,0,ans+'0');
        binaryStrings(n-1,1,ans+'1');
    }
    else{
        binaryStrings(n-1 , 0,ans+'0');
    }
}
void binaryStrings(int n, string ans){
    if(n == 0){
        cout<<ans<<endl;
        return;
    }
    if(ans[ans.size()-1] != '1'){
        binaryStrings(n-1,ans+'0');
        binaryStrings(n-1,ans+'1');
    }
    else{
        binaryStrings(n-1,ans+'0');
    }
}
int main(){
    int n;
    cin>>n;
    string ans = "";
    binaryStrings(n , ans);
}