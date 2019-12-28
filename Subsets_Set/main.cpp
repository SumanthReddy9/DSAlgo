#include<bits/stdc++.h>
using namespace std;

void getSubsetsU(int arr[], int brr[], int l, int r, int k, int pos){
    if(pos == k){
        for(int i=0;i<k;i++){
            cout<<brr[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(l > r)
        return;

    brr[pos] = arr[l];
    getSubsetsU(arr, brr, l+1, r, k, pos+1);
    getSubsetsU(arr, brr, l+1, r, k, pos);
}

void getSubsets(int s[], int n){
    for(int i=1;i<=n;i++){
        int brr[i];
        getSubsetsU(s, brr, 0, n-1, i, 0);
    }
}

int main(){
    int n;
    cin>>n;
    set<int> s;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        s.insert(t);
    }
    int l = s.size();
    int arr[l];
    set<int>:: iterator it;
    int i = 0;
    for( it = s.begin(); it!=s.end(); ++it){
        arr[i] = *it;
        i++;
    }
    getSubsets(arr, l);
}
