#include<bits/stdc++.h>
using namespace std;

void getBig(int arr[], int n, int k){
    while(k--){
        int lar = INT_MIN, idx = -1, idy = -1, tempIdx = -1;
        for(int i = n-1;i>=0;i--){
            if(arr[i] > lar){
                lar = arr[i];
                tempIdx = i;
            }
            else if(lar - arr[i] > 0){
                idy = i;
                idx = tempIdx;
            }
        }
        if(idx != -1 && idy != -1)
            swap(arr[idx], arr[idy]);
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cin>>k;
    getBig(arr, n, k);
}
