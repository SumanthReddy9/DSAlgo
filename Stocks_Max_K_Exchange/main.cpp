#include<bits/stdc++.h>
using namespace std;

void getMaxProfit(int arr[], int n, int k){
    int dp[k+1][n];
    for(int i=0;i<n;i++){
        dp[0][i] = 0;
    }
    for(int i=0;i<=k;i++){
        dp[i][0] = 0;
    }
    for(int i=1;i<=k;i++){
        int prevDiff = INT_MIN;
        for(int j=1;j<n;j++){
            prevDiff = max(prevDiff, dp[i-1][j-1]-arr[j-1]);
            dp[i][j] = max(dp[i][j-1], prevDiff+arr[j]);
        }
    }

    for(int i=0;i<=k;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[k][n-1];
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    getMaxProfit(arr, n, k);
}
