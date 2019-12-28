//Split the given array into K sub-arrays such that maximum sum of all sub arrays is minimum

#include<bits/stdc++.h>
using namespace std;

bool check(int mid, int arr[], int n, int k){
    int countVal = 0, sum = 0;
    for(int i=0;i<n;i++){
        if(arr[i] > mid)
            return false;
        sum += arr[i];
        if(sum > mid){
            countVal++;
            sum = arr[i];
        }
    }
    countVal++;
    if(countVal <= k)
        return true;
    return false;
}

int solve(int arr[], int n, int k){
    int startVal = 1;
    int endVal = 0;
    for(int i=0;i<n;i++)
        endVal += arr[i];
    int ans = 0;
    while(startVal <= endVal){
        int mid = (startVal + endVal)/2;
        if(check(mid, arr, n, k)){
            ans = mid;
            endVal = mid-1;
        }
        else{
            startVal = mid + 1;
        }
    }
    return ans;
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
    cout<<solve(arr, n, k);
}
