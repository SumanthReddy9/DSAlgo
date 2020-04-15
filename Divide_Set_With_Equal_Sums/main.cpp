#include<bits/stdc++.h>
using namespace std;

bool check(int arr[], int n, int sum){
    if(sum == 0)
        return true;
    if(n == 0 && sum != 0)
        return false;
    if(sum < arr[n-1]){
        return check(arr, n-1, sum);
    }
    return (check(arr, n-1, sum) || check(arr, n-1, sum - arr[n-1]));
}

bool isPossible(int arr[], int n){
    int sum = 0;
    for(int i=0;i<n;i++)
        sum += arr[i];
    if(sum%2 != 0)
        return false;
    return check(arr, n, sum/2);
}

/*void check2(int arr[], int brr[], int n, int half, int bidx, int aidx, int i, int &f){
    if(bidx == i){
        int temp = 0;
        for(int j=0;j<i;j++)
            temp += brr[j];
        if(temp == half)
            f = 1;
        return;
    }
    if(aidx > n){
        return;
    }
    brr[bidx] = arr[aidx];
    check2(arr, brr, n, half, bidx+1, aidx+1, i, f);
    check2(arr, brr, n, half, bidx, aidx+1, i, f);
}

bool findPartiion(int arr[], int n, int half){
    int f = 0;
    for(int i=1;i<=n;i++){
        if(f == 0){
            int brr[i];
            check2(arr, brr, n-1, half, 0, 0, i, f);
        }
        else{
            return true;
        }
    }
    return false;
}*/

bool findPartiion(int arr[], int n, int sum){
    int dp[sum+1][n+1];
    for(int i=0;i<n+1;i++)
        dp[0][i] = true;
    for(int i=1;i<sum+1;i++)
        dp[i][0] = false;
    for(int i=1;i<=sum;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = dp[i][j-1];
            if(i >= arr[j-1]){
                dp[i][j] = dp[i][j] || dp[i - arr[j-1]][j-1];
            }
        }
    }
    for(int i=0;i<=sum;i++){
        for(int j=0;j<=n;j++){
            cout<<dp[i][j]<<"    ";
        }
        cout<<endl;
    }
    return dp[sum][n];
}

int main(){
    int n;
    cin>>n;
    int arr[n], temp = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        temp += arr[i];
    }
    if(isPossible(arr, n)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    cout<<endl;
    if(temp%2){
        cout<<"NO";
    }
    else{
        if(findPartiion(arr, n, temp/2)){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
    }
}
