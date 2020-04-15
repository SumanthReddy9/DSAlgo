#include<bits/stdc++.h>
using namespace std;

/*void getPaliondromes(string str, int n){
    bool dp[n][n];
    memset(dp, false, sizeof(dp));
    vector<string>vec;
    for(int i=0;i<n;i++){
        dp[i][i] = true;
        if(find(vec.begin(), vec.end(), str.substr(i, 1)) == vec.end())
            vec.push_back(str.substr(i, 1));
    }
    for(int i=0;i<n-1;i++){
        if(str[i] == str[i+1]){
            dp[i][i+1] = true;
            if(find(vec.begin(), vec.end(), str.substr(i, 2)) == vec.end()){
                vec.push_back(str.substr(i, 2));
            }
        }
    }
    for(int k=3;k<=n;k++){
        for(int i=0;i<n-k+1;i++){
            int j = i+k-1;
            if(str[i] == str[j] && dp[i+1][j-1]){
                dp[i][j] = true;
                if(find(vec.begin(), vec.end(), str.substr(i, k)) == vec.end()){
                    vec.push_back(str.substr(i, k));
                }
            }
        }
    }
    cout<<vec.size();
}
*/
void getPaliondromes(string str, int n){
    bool dp[n][n];
    memset(dp, false, sizeof(dp));
    vector<string>vec;
    for(int i=0;i<n;i++){
        dp[i][i] = true;
        if(find(vec.begin(), vec.end(), str.substr(i, 1)) == vec.end()){
            vec.push_back(str.substr(i, 1));
        }
    }
    for(int i=0;i<n-1;i++){
        if(str[i] == str[i+1]){
            dp[i][i+1] = true;
            if(find(vec.begin(), vec.end(), str.substr(i, 2)) == vec.end()){
                vec.push_back(str.substr(i, 2));
            }
        }
    }
    for(int k=3;k<=n;k++){
        for(int i=0;i<n-k+1;i++){
            int j = k+i-1;
            if(str[i] == str[j] && dp[i+1][j-1]){
                dp[i][j] = true;
                if(find(vec.begin(), vec.end(), str.substr(i, k)) == vec.end()){
                    vec.push_back(str.substr(i, k));
                }
            }
        }
    }
    cout<<vec.size();
}

int main(){
    string str;
    cin>>str;
    int l = str.length();
    getPaliondromes(str, l);
}
