#include<bits/stdc++.h>
using namespace std;

int partitionQS(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j = low; j< high; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    cout<<arr[high]<<" "<<pivot<<endl;
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(int arr[], int s, int e){
    if(s < e){
        int pi = partitionQS(arr, s, e);
        quickSort(arr, s, pi-1);
        quickSort(arr, pi+1, e);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    quickSort(arr, 0, n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}