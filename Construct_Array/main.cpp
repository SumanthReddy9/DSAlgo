#include<bits/stdc++.h>
using namespace std;

void getCount(int n, int k, int x){
    int dp[n][2];
    dp[0][0] = 1;
    dp[0][1] = 0;
    for(int i=1;i<n;i++){
        dp[i][0] = dp[i-1][1]*(k-1);
        dp[i][1] = dp[i-1][1]*(k-2) + dp[i-1][0];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n, k, x;
    cin>>n>>k>>x;
    getCount(n, k, x);
}
