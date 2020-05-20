#include<bits/stdc++.h>
using namespace std;

int partitionQS(int arr[], int l, int r){
    int pivot = arr[r];
    int i = l;
    for(int j=l;j<r;j++){
        if(arr[j] <= pivot){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int KthSmallestQS(int arr[], int l, int r, int k){
    if(k>0 && k<=r-l+1){
        int pos = partitionQS(arr, l, r);
        if(pos -l == k-1){
            return arr[pos];
        }
        if(pos-l > k-1){
            return KthSmallestQS(arr, l, pos-1, k);
        }
        return KthSmallestQS(arr, pos+1, r, k-pos+l-1);
    }
    else{
        return INT_MAX;
    }
}

void getKthSmallest(int arr[], int n, int k){
    cout<<KthSmallestQS(arr, 0, n-1, k);
}

int main(){
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    getKthSmallest(arr, n, k);
}






//3, 4, 8, 1, 2, 9

//k = 2
