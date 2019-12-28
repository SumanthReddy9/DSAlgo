#include<bits/stdc++.h>
using namespace std;

void mergeit(int arr[], int l, int m, int r){
    int n1 = m-l+1, n2 = r-m;
    int larr[n1], rarr[n2];
    for(int i=0;i<n1;i++){
        larr[i] = arr[l+i];
    }
    for(int j=0;j<n2;j++){
        rarr[j] = arr[m+j+1];
    }
    int i=0, j=0, k = l;
    while(i<n1 && j<n2){
        if(larr[i] > rarr[j]){
            arr[k] = rarr[j];
            j++;
        }
        else{
            arr[k] = larr[i];
            i++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = larr[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = rarr[j];
        j++;
        k++;
    }
}

void msort(int arr[], int l, int r){
    if(l < r){
        int m = (l+r)/2;
        msort(arr, l, m);
        msort(arr, m+1, r);
        mergeit(arr, l, m, r);
    }
}

void findCount(int arr[], int n, int k){
    int l = 0;
    int r = n-1;
    int lg = n;
    while(l<=r){
        int m = (l+r)/2;
        if(arr[m] > k){
            lg = m;
            r = m-1;
        }
        else{
            l = m+1;
        }
    }
    cout<<n-lg;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    msort(arr, 0, n-1);
    int k;
    cin>>k;
    findCount(arr, n, k);
}
