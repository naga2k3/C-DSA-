#include <bits/stdc++.h>
using namespace std;
void removeDuplicate(string str,string ans,int i,bool map[]){
    if(i == str.size()){
        cout<<ans;
        return;
    }
    int mapIdx = (int)(str[i]-'a');
    if(map[mapIdx]){
        removeDuplicate(str,ans,i+1,map);
    }
    else{
        map[mapIdx] = true;
        removeDuplicate(str,ans+str[i],i+1,map);
    }
}
void removeDuplicate1(string str,string ans,bool map[]){
    if(str.size() == 0){
        cout<<ans;
        return;
    }
    int n = str.size();
    char ch = str[n-1];
    int mapIdx = (int)(ch -'a');
    str = str.substr(0 , n-1);
    if(map[mapIdx]){
        removeDuplicate1(str,ans,map);
    }
    else{
        map[mapIdx] = true;
        removeDuplicate1(str,ch+ans,map);
    }
}

int main(){
    string str;
    getline(cin ,str);
    bool map[26] = {false};
    string ans = "";
    // removeDuplicate(str,ans,0,map);
    removeDuplicate1(str,ans,map);
}