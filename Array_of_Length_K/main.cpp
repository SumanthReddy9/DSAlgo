#include<bits/stdc++.h>
using namespace std;

void getKSizeArrPrint(int arr[], int n, int k, int brr[], int index, int curidx){
    if(curidx == k){
        for(int i=0;i<k;i++){
            cout<<brr[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(index >= n){
        return;
    }

    brr[curidx] = arr[index];
    getKSizeArrPrint(arr, n, k, brr, index+1, curidx+1);
    getKSizeArrPrint(arr, n, k, brr, index+1, curidx);
}

void getKSizeArr(int arr[], int n, int k){
    int brr[k];
    getKSizeArrPrint(arr, n, k, brr, 0, 0);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cin>>k;
    getKSizeArr(arr, n, k);
}
