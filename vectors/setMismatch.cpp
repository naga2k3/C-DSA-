#include <bits\stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>freq(n+1,0);
    for(int i=0;i<n;i++){
        freq[nums[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(freq[i] == 2){
            arr[0]=i;
        }
        else if(freq[i] == 0){
            arr[1]=i;
        }
    }
    cout<<arr[0]<<" "<<arr[1];
    return 0;
}