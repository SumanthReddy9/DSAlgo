#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    int dp[n+1][k+1];
    dp[0][0] = 1;
    for(int i=1;i<=k;i++){
        dp[0][i] = 1;
        dp[1][i] = 26;
    }
    dp[1][0] = 21;
    for(int j=0;j<=k;j++){
        for(int i=2;i<=n;i++){
            if(j>0)
                dp[i][j] = 21*(dp[i-1][j] + 5*dp[i-2][j-1]);
            else
                dp[i][j] = 21*dp[i-1][j];
            if(j == i && j == k){
                dp[i][j] += pow(5, k);
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    //cout<<dp[n][k];
}
