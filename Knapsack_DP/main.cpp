#include<bits/stdc++.h>
using namespace std;

void Knapsack(int wt[], int cost[], int n, int m){
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
   for(int i = 1; i<= n ; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = dp[i-1][j];
            if(j-wt[i-1] >= 0){
                dp[i][j] = max(dp[i][j], dp[i-1][j-wt[i-1]] + cost[i-1]);
                dp[i][j] = max(dp[i][j], dp[i][j-wt[i-1]]+cost[i-1]);
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][m];
}

int KnapsackR(int wt[], int cost[], int n, int m){
    if(n==0 || m==0){
        return 0;
    }
    if(wt[n-1] > m){
        return KnapsackR(wt, cost, n-1, m);
    }
    else{
        return max(wt[n-1] + KnapsackR(wt, cost, n-1, m-wt[n-1]), KnapsackR(wt, cost, n-1, m));
    }
}

int main(){
    int n;
    cin>>n;
    int wt[n], cost[n];
    for(int i=0;i<n;i++){
        cin>>wt[i]>>cost[i];
    }
    int m;
    cin>>m;
    //cout<<KnapsackR(wt, cost, n, m)<<endl;
    Knapsack(wt, cost, n, m);
}
