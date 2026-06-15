#include <bits/stdc++.h>
using namespace std;
int main(){
    string st1;
    string st2;
    getline(cin , st1);
    getline(cin , st2);
    if(st1.length() != st2.length()){
        cout<<"Not Valid Anagram";
        return 0;
    }
    int a[26] = {0};
    for(int i=0;i<st1.length();i++){
        int idx = st1[i]-'a';
        a[idx]++;
    }
    for(int i=0;i<25;i++){
        cout<<a[i];
    }

    for(int i=0 ;i<st2.length();i++){
        int idx = st2[i]-'a';
        if(a[idx] == 0){
            cout<<"Not Valid Anagram";
            return 0;
        }
        a[idx]--;
    }
    cout<<" Valid Anagram";
    return 0;
}