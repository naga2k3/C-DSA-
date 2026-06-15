#include <bits/stdc++.h>
using namespace std;
void trappingRainWater(int height[],int n){
    stack<int>st;
    int water = 0;
    for(int i=0;i<n;i++){
        while(!st.empty() && height[i] > height[st.top()]){
            int top = st.top();
            st.pop();
            if(st.empty()) break;
            int distance = i-st.top()-1;
            int boundedHeight = min(height[i], height[st.top()]) - height[top];
            water += distance * boundedHeight;
        }
        st.push(i);
    }
    cout << water;
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