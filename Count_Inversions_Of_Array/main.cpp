//Two elements a[i] and a[j] form an inversion if
//     a[i] > a[j] and i < j. For simplicity, we may
//     assume that all elements are unique.

#include<bits/stdc++.h>

using namespace std;

int sumUp(int BIT[], int idx){
    int ans = 0;
    while(idx > 0){
        ans += BIT[idx];
        idx -= (idx & -idx);
    }
    return ans;
}

void update(int BIT[], int idx, int maxEle, int val){
    while(idx <= maxEle){
        BIT[idx] += val;
        idx += (idx & -idx);
    }
}

int getCount(int arr[], int n){
    int maxEle = arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i] > maxEle)
            maxEle = arr[i];
    }
    int BIT[maxEle+1];
    int ans = 0;
    for(int i=0;i<=maxEle;i++)
        BIT[i] = 0;
    for(int i=n-1;i>=0;i--){
        ans += sumUp(BIT, arr[i]-1);
        update(BIT, arr[i], maxEle, 1);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<getCount(arr, n);
}
