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

void check2(int arr[], int brr[], int n, int half, int bidx, int aidx, int i, int &f){
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
    if(findPartiion(arr, n, temp/2)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}
