#include<bits/stdc++.h>
using namespace std;

void findMaxPalindrome(string str, int l){
    int dp[l][l];
    int maxLen = 0, s = 0;
    memset(dp, 0, sizeof(dp));
    for(int i=0;i<l;i++){
        dp[i][i] = 1;
        maxLen = 1;
    }

    for(int i=0;i<l-1;i++){
        if(str[i] == str[i+1]){
            dp[i][i+1] = 1;
            maxLen = 2;
            s = i;
        }
    }
    for(int i=3;i<=l;i++){
        for(int j=0; j<l-i+1;j++){
            int k = j+i-1;
            if(str[j] == str[k]){
                if(dp[j+1][k-1] == 1){
                    dp[j][k] = 1;
                    if(maxLen < i){
                        s = j;
                        maxLen = i;
                    }
                }
            }
        }
    }
    for(int i=s;i<s+maxLen;i++){
        cout<<str[i];
    }
    cout<<endl;
    cout<<maxLen<<endl;
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    string str;
    cin>>str;
    int l = str.length();
    findMaxPalindrome(str, l);
}
