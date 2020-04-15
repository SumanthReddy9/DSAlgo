#include<bits/stdc++.h>
using namespace std;

int getNum(int arr[], int n, int c){
    if(n == 0){
        return 1;
    }
    if(n < 0){
        return 0;
    }
    if(c <= 0 && n > 0){
        return 0;
    }
    return getNum(arr, n-arr[c-1], c) + getNum(arr, n, c-1);
}

void getNumdp1(int arr[], int n, int c){
    int dp[n+1][c];
    for(int i=0;i<c;i++){
        dp[0][i] = 1;
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<c;j++){
            int x = 0, y = 0;
            if(i - arr[j] >= 0){
                x = dp[i - arr[j]][j];
            }
            if(j >= 1){
                y = dp[i][j-1];
            }
            dp[i][j] = x + y;
        }
    }
    cout<<dp[n][c-1]<<endl;
}

void getNumdp2(int arr[], int n, int c){
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i=0;i<c;i++){
        for(int j = arr[i]; j <= n; j++){
            dp[j] += dp[j-arr[i]];
        }
    }
    cout<<dp[n];
}

int main(){
    int n;
    int c;
    cin>>n>>c;
    int arr[c];
    for(int i=0;i<c;i++)
        cin>>arr[i];
    cout<<getNum(arr, n, c)<<endl;
    getNumdp1(arr, n, c);
    getNumdp2(arr, n, c);
}
