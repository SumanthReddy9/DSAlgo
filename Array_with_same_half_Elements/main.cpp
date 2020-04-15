#include<bits/stdc++.h>
using namespace std;

int getIndexL(int arr[], int s, int e, int ele){
    if(s < e){
        int m = (s+e)/2;
        if(arr[m] == ele){
            if(m == 0)
                return m;
            if(arr[m-1] != arr[m])
                return m;
        }
        if(ele > arr[m]){
            return getIndexL(arr, m+1, e, ele);
        }
        return getIndexL(arr, s, m-1, ele);
    }
}

int getIndexR(int arr[], int s, int e, int ele){
    if(s < e){
        int m = (s+e)/2;
        if(arr[m] == ele){
            if(m == e-1)
                return m;
            if(arr[m+1] != arr[m])
                return m;
        }
        if(ele < arr[m]){
            return getIndexR(arr, s, m-1, ele);
        }
        return getIndexR(arr, m+1, e, ele);
    }
}
bool isHalfElementsRepeated(int arr[], int n){
    if(n%2 == 0){
        if(arr[0] == arr[n/2-1])
            return true;
        if(arr[n/2] == arr[n-1])
            return true;
    }
    int i = getIndexL(arr, 0, n/2, arr[n/2]);
    cout<<i<<endl;
    int j = getIndexR(arr, n/2, n, arr[n/2]);
    cout<<j<<endl;

    if(j - i + 1 >= n/2){
        return true;
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(isHalfElementsRepeated(arr, n))
        cout<<"Yes";
    else
        cout<<"No";
}
