#include <bits/stdc++.h>
using namespace std;


int main(){
    char ch[1000];
    cin.getline(ch, 1000);
    int n = strlen(ch);
    char ch1[n];
    strcpy(ch1,ch);
    for(int i=0;i<n;i++){
        swap(ch[i],ch[n-1]);
        n--;
    }
    cout<<ch<<endl;
    if(strcmp(ch1,ch) == 0){
        cout<<"Is Valid Palindrome";
    }
    else{
        cout<<"Not valid Palindrome";
    }
}  