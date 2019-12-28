#include<bits/stdc++.h>
using namespace std;

void getMaxAmount(int arr[], int n){
    int dp[n];
    memset(dp, 0, sizeof(dp));
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for(int i=2;i<n;i++){
        dp[i] = max(dp[i-1], arr[i]+dp[i-2]);
    }
    cout<<dp[n-1]<<endl;
}

void getMaxAmount2(int arr[], int n){
    int ans = 0;
    int t1, t2;
    if(n>=1){
        t1 = ans = arr[0];
    }
    if(n>=2){
        t2 = ans = max(arr[0], arr[1]);
    }
    if(n>2){
        for(int i=2;i<n;i++){
            ans = max(t2, arr[i]+t1);
            t1 = t2;
            t2 = ans;
        }
    }
    cout<<ans<<endl;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    getMaxAmount(arr, n);
    getMaxAmount2(arr, n);
}
