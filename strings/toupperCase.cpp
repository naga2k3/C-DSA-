#include <bits/stdc++.h>
using namespace std;

void toUpper(char ch[] , int n){
    for(int i=0;i<n;i++){
        if(ch[i] > 'Z' && ch[i] <= 'z'){
            ch[i] = ch[i] - 32;
        }
    }
    cout<<"To UpperCase : "<<ch<<endl;;

}

void toLower(char ch[] , int n){
    for(int i=0;i<n;i++){
        if(ch[i] <= 'Z' && ch[i] >= 'A'){
            ch[i] = ch[i] + 32;
        }
    }
    cout<<"To LowerCase : "<<ch;
}

int main(){
    char ch[1000];
    cin.getline(ch , 1000);
    toUpper(ch , strlen(ch));
    toLower(ch ,strlen(ch));
}