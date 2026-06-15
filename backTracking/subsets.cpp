#include <bits/stdc++.h>
using namespace std;
void findSubset(string str , string subset){
    if(str.size() == 0){
        cout<<subset<<endl;
        return;
    }
    char ch = str[0];
    findSubset(str.substr(1,str.size()-1), subset+ch);
    findSubset(str.substr(1,str.size()-1), subset);
}
int main(){
    string str;
    getline(cin , str);
    findSubset(str , " ");
}