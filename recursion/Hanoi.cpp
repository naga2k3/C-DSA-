#include <bits/stdc++.h>
using namespace std;
void towerOfHanoi(int n,string src,string helper,string dest){
    if(n == 1){
        cout<<"tarnsfer disk "<<n<<" from "<<src<<" to "<<dest<<endl;
        return;
    }
    towerOfHanoi(n-1, src,dest,helper);
    cout<<"tarnsfer disk "<<n<<" from "<<src<<" to "<<dest<<endl;
    towerOfHanoi(n-1,helper,src,dest);
}
int main(){
    int n;
    cin>>n;
    towerOfHanoi(n,"A","B","C");
}