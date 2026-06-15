#include <bits/stdc++.h>
using namespace std;

void palindrome(int n){
    int original_n = n;
    int reverse = 0;
    while(n>0){
        int LD = n%10;
        reverse = reverse*10 + LD;
        n = n/10;
    }
    if(reverse == original_n){
        cout<<"It is a Palindrome";
    } else {
        cout<<"Not a Palindrome";
    }
}
int main(){
    int n;
    cin>>n;
    palindrome(n);
}