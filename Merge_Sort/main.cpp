#include <bits/stdc++.h>
using namespace std;

void mergeSortU(int arr[], int low, int mid, int high){
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int l[n1], r[n2];
    for(int i=0; i<n1; i++){
        l[i] = arr[low+i];
    }
    for(int j=0;j<n2;j++){
        r[j] = arr[mid+j+1];
    }
    int i = 0, j = 0, k = low;
    while(i < n1 && j < n2){
        if(l[i] > r[j]){
            arr[k] = r[j];
            j++;
        }
        else{
            arr[k] = l[i];
            i++;
        }
        k++;
    }
    while(i < n1){
        arr[k] = l[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = r[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int low, int high){
    if(low < high){
        int mid = (low+high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        mergeSortU(arr, low, mid, high);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    mergeSort(arr, 0, n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
