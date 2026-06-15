#include <bits/stdc++.h>
using namespace std;

void maxSubArray(int a[],int n){
    int maxSum = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum = 0;
            for(int k=i;k<=j;k++){
                sum = sum + a[k];
                maxSum = max(maxSum,sum);
            }
            cout<<sum<<" ";
        }
        cout<<endl;
    }
    cout<<maxSum<<endl;
}

void maxSubArrayOptimized(int a[],int n){
    int maxSum = INT_MIN;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum = sum + a[j];
            maxSum = max(maxSum,sum);
        }
    }
    cout<<maxSum<<endl;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    maxSubArray(a,n);
    maxSubArrayOptimized(a,n);
}