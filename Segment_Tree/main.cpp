#include<bits/stdc++.h>
using namespace std;

int CSTU(int arr[], int ss, int se, int *st, int si){
    if(ss == se){
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = (ss+se)/2;
    st[si] = CSTU(arr, ss, mid, st, 2*si+1) + CSTU(arr, mid+1, se, st, 2*si+2);
    return st[si];
}

int *CST(int arr[], int n){
    int x = ceil(log(n)/log(2));
    int max_size = 2*(pow(2, x)) - 1;
    int *st = new int[max_size];
    CSTU(arr, 0, n-1, st, 0);
    return st;
}

int getSumU(int *st, int ss, int se, int qs, int qe, int si){
    if(qs <= ss && qe >= se){
        return st[si];
    }
    if(se<qs || ss>qe){
        return 0;
    }
    int mid = (ss+se)/2;
    return getSumU(st, ss, mid, qs, qe, 2*si+1) + getSumU(st, mid+1, se, qs, qe, 2*si+2);
}

int getSum(int *st, int qs, int qe, int n){
    if(qs<0 || qe>n-1 || qs > qe){
        return 0;
    }
    return getSumU(st, 0, n-1, qs, qe, 0);
}

void updateSTU(int *st, int ss, int se, int i, int diff, int si){
    if(i<ss || i>se){
        return;
    }
    st[si] = st[si] + diff;
    if(se != ss){
        int mid = (ss+se)/2;
        updateSTU(st, ss, mid, i, diff, 2*i+1);
        updateSTU(st, mid+1, se, i, diff, 2*i+2);
    }
}

void updateST(int *st, int arr[], int n, int i, int val){
    if(i<0 || i>n-1){
        return;
    }
    int diff = val - arr[i];
    arr[i] = val;
    updateSTU(st, 0, n-1, i, diff, 0);
}

void update(int brr[], int idx, int val, int n){
    while(idx<=n){
        brr[idx] += val;
        idx += (idx & -idx);
    }
}

int query(int brr[], int idx){
    int ans = 0;
    while(idx){
        ans += brr[idx];
        idx -= (idx & -idx);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int *st = CST(arr, n);
    int brr[n+1];
    memset(brr, 0, sizeof(brr));
    for(int i=1;i<=n;i++)
        update(brr, i+1, arr[i], n);
    int idx1, idx2;
    cin>>idx1>>idx2;
    cout<<getSum(st, idx1, idx2, n)<<endl;
    cout<<(query(brr, idx2+1) - query(brr, idx1))<<endl;
    int idx, val;
    cin>>idx>>val;
    int t = arr[idx];
    updateST(st, arr, n, idx, val);
    update(brr, idx+1, val-t, n);
    cout<<(query(brr, idx2+1) - query(brr, idx1))<<endl;
}
