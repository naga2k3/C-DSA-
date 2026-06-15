#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector <int> height(n);
    for(int i=0;i<n;i++){
        cin>>height[i];
    }
    int st = 0;
    int end = n-1;
    int mostWater =0;
    while(st < end){
        int h = min(height[st], height[end]);
        int w = end - st;
        mostWater = max(mostWater , h*w);
        if(height[st]< height[end]){
            st++;
        }
        else{
            end--;
        }
    }
    cout<<mostWater;
}