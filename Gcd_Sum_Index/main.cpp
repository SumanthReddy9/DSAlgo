#include<bits/stdc++.h>
#define MAX 500001
#define mod 1000000007
using namespace std;

long long A[MAX];
long long G[MAX];
long long arr[1000001];

void etiontfunc(){
    for(long long i=1;i<MAX; i++){
        A[i] = i;
    }
    for(long long i = 2; i<MAX; i++){
        if(A[i] == i){
            A[i] = i-1;
            for(long long j = 2*i; j<MAX; j += i){
                A[j] = (A[j]/i)*(i-1);
            }
        }
    }
}

void pillaiAlgorithm(){
    for(long long i=1;i<MAX;i++){
        G[i] = i;
    }
    for(long long i = 1; i< MAX; i++){
        for(long long j = 2*i; j<MAX; j+=i){
            G[j] += A[j/i]*i;
        }
    }
}

/*void update(long long idx, long long t, long long n){
    while(idx <= n){
        arr[idx] += t;
        idx += (idx & -idx);
    }
}

long long query(long long x){
    long long ans = 0;
    while(x){
        ans += arr[x];
        x -= (x & -x);
    }
    return ans;
}*/

void update(long long idx, long long t, long long n){
    while(idx <= n){
        arr[idx] += t;
        idx += (idx & -idx);
    }
}

long long query(long long x){
    long long ans = 0;
    while(x){
        ans += arr[x];
        x -= (x & -x);
    }
    return ans;
}

int main(){
    A[0] = G[0] = 0;
    etiontfunc();
    pillaiAlgorithm();
    for(int i=1;i<=10;i++){
        cout<<A[i]<<"    "<<G[i]<<endl;
    }
    long long n;
    cin>>n;

    long long v[n+1];
    memset(arr, 0, sizeof(arr));
    v[0] = 0;
    for(long long i=1;i<=n;i++){
        cin>>v[i];
    }
     for(long long i=1;i<=n;i++){
        update(i, G[v[i]], n);
    }
    long long x;
    cin>>x;
    while(x--){
        char c;
        long long a, b;
        cin>>c>>a>>b;
        if(c == 'C'){
            long long ans = (query(b) - query(a-1))%mod;
            cout<<ans<<endl;
        }
        else{
            update(a, G[b] - G[v[a]], n);
            v[a] = b;
        }
    }
}
