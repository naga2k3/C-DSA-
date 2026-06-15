#include <bits/stdc++.h>
using namespace std;

void trappingRainWater(int height[],int n){
    int leftMax[n];
    leftMax[0] = height[0];
    int rightMax[n];
    cout<<leftMax[0]<<" ";
    for(int i=1;i<n;i++){
        leftMax[i] = max(leftMax[i-1], height[i-1]);
        cout<<leftMax[i]<<" ";
    }
    cout<<endl;
    rightMax[n-1]= height[n-1];
    for(int i=n-2;i>=0;i--){
        rightMax[i] = max(rightMax[i+1], height[i+1]);
    }
    for(int i=0;i<n;i++){
        cout<<rightMax[i]<<" ";
    }
    cout<<endl;
    int sum=0;
    for(int i=0;i<n;i++){
        int curr = min(leftMax[i] , rightMax[i]) - height[i];
        if(curr > 0){
            sum = sum + curr;
        }
    }
    cout<<sum;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    trappingRainWater(a,n);
}