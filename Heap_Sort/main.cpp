#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int i, int n){
    int lar = i;
    int x = 2*i +1;
    int y = 2*i +2;
    if(x < n && arr[x] < arr[lar])
        lar = x;
    if(y < n && arr[y] < arr[lar])
        lar = y;
    if(lar != i){
        swap(arr[i], arr[lar]);
        heapify(arr, lar, n);
    }
}

void heapSort(int arr[], int n){
    for(int i = n/2-1; i>=0; i--){
        heapify(arr, i, n);
    }
    for(int i=n-1; i>=0;i--){
        swap(arr[0], arr[i]);
        cout<<arr[i]<<" ";
        heapify(arr, 0, i);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    heapSort(arr, n);
}
