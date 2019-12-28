//Find number of triplets in array such that a[i]>a[j]>a[k] and i<j<k


#include<bits/stdc++.h>
using namespace std;

int query(int BIT[], int idx){
    int sum = 0;
    while(idx){
        sum += BIT[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int BIT[], int idx, int val, int n){
    while(idx <= n){
        BIT[idx] += val;
        idx += (idx & -idx);
    }
}

void Convert(int arr[], int n){
    int temp[n];
    for(int i=0;i<n;i++){
        temp[i] = arr[i];
    }
    sort(temp, temp+n);
    for(int i=0;i<n;i++){
        arr[i] = lower_bound(temp, temp+n, arr[i]) - temp + 1;
    }
}


int getTipletCount(int arr[], int n){
    Convert(arr, n);
    int BIT[n + 1] = { 0 };
    int smaller_right[n + 1] = { 0 };
    int greater_left[n + 1] = { 0 };

    for(int i=n-1;i>=0;i--){
        smaller_right[i] = query(BIT, arr[i]-1);
        update(BIT, arr[i], 1, n);
    }
    for(int i=0;i<=n;i++){
        BIT[i] = 0;
    }

    for(int i=0;i<n;i++){
        greater_left[i] = i - query(BIT, arr[i]);
        update(BIT, arr[i], 1, n);
    }
    int ans  = 0;
    for(int i=0;i<n;i++){
        ans += greater_left[i]*smaller_right[i];
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
    cout<<getTipletCount(arr, n);
}
