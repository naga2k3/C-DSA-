#include <bits/stdc++.h>
using namespace std;

void buySellStocks(int a[],int n){
    int bestBuy[n];
    bestBuy[0] = INT_MAX;
    for(int i=1;i<n;i++){
        bestBuy[i] = min(bestBuy[i-1] , a[i-1]);
        cout<<bestBuy[i]<<" ";
    }
    cout<<endl;
    int profit[n];
    int maxProfit = 0;
    for(int i=0;i<n;i++){
        profit[i] = a[i] - bestBuy[i];
        cout<<profit[i]<<" ";
        maxProfit = max(maxProfit , profit[i]);
    }
    cout<<endl;
    cout<<"MaxProfit: "<<maxProfit;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    buySellStocks(a,n);
}