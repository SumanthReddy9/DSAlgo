#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int rep[200005];
long long sizeArr[200005];

int root(int i){
    while(rep[i] != i){
        rep[i] = rep[rep[i]];
        i = rep[i];
    }
    return i;
}

void union1(int x, int y){
    if(sizeArr[x] < sizeArr[y]){
        rep[x] = y;
        sizeArr[y] += sizeArr[x];
    }
    else{
        rep[y] = x;
        sizeArr[x] += sizeArr[y];
    }
}

int partitionQS(vector<pair<long long, pair<int, int> > >&adj, int s, int e){
    int pivot = adj[e].first;
    int i = s-1;
    for(int j=s;j<e;j++){
        if(adj[j].first <= pivot){
            i++;
            swap(adj[i], adj[j]);
        }
    }
    swap(adj[i+1], adj[e]);
    return i+1;
}

void quickSort(vector<pair<long long, pair<int, int> > >&adj, int s, int e){
    if(s<e){
        int i = partitionQS(adj, s, e);
        quickSort(adj, s, i-1);
        quickSort(adj, i+1, e);
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int x=0;x<=n;x++){
            rep[x] = x;
            sizeArr[x] = 1;
        }
        vector<pair<long long, pair<int, int> > >p;
        for(int i=1;i<n;i++){
            int a, b;
            long long w;
            cin>>a>>b>>w;
            p.push_back(make_pair(w, make_pair(a, b)));
        }
        quickSort(p, 0, n-2);
        //sort(p.begin(), p.end());
        long long ans = 0;
        for(int i=0;i<p.size();i++){
            int x = root(p[i].second.first);
            int y = root(p[i].second.second);
            ans += p[i].first*sizeArr[x]*sizeArr[y];
            ans = ans%1000000007;
            union1(x, y);
        }
        cout<<ans<<endl;
    }
    return 0;
}
