#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"enter a number:";
    cin>>n;
    bool is_prime = true;
    for(int i=2;i<n;i++){
        if(n%i == 0){
            is_prime = false;
            break;
        }
    }
    if(is_prime == true){
        cout<<"Prime Number";
    }
    else{
        cout<<"Not Prime Number";
    }
    return 0;
}