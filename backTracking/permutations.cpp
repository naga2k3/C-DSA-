#include <bits/stdc++.h>
using namespace std;
void getPermutations(string str , string permutations){
    if(str.size() == 0){
        cout<<permutations<<" ";
        return;
    }
    for(int i=0;i<str.size();i++){
        char ch = str[i];
        string str1 = str.substr(0,i) + str.substr(i+1);
        getPermutations(str1,permutations+ch);
    }
}
int main(){
    string str;
    getline(cin , str);
    getPermutations(str ,"");
}