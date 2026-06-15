#include <bits/stdc++.h>
using namespace std;

int main(){
    string s1,s2;
    cin>>s1>>s2;
    if(s1.length() != s2.length()){
        cout<<"false";
        return 0;
    }
    int freq1[26] = {0};
    int freq2[26] = {0};
    for(char ch :s1){
        freq1[ch-'a']++;
    }
    for(char ch :s2){
        freq2[ch-'a']++;
    }
    for(int i=0;i<26;i++){
        if((freq1[i] != 0 && freq2[i] == 0) || (freq1[i] == 0 && freq2[i] != 0)){
            cout<<"false";
            return 0;
        }
    }
    sort(freq1,freq1+26);
    sort(freq2,freq2+26);
    for(int i=0;i<26;i++){
        if(freq1[i] != freq2[i]){
            cout<<"false";
            return 0;
        }
    }
    cout<<"true";
    return 0;
}
