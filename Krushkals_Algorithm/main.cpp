#include<bits/stdc++.h>
using namespace std;

int root(int x, int idx[]){
    int ans = 0;
    while(idx[x] != x){
        idx[x] = idx[idx[x]];
        x = idx[x];
    }
}

void union1(int x, int y, int idx[]){
    idx[root(x, idx)] = idx[root(y, idx)];
}

void KrushkalMST(vector<pair<int, pair<int, int> > >adj, int v, int e, int idx[]){
    int cost = 0;
    for(int i=0;i<e;i++){
        if(root(adj[i].second.first, idx) != root(adj[i].second.second, idx)){
            cout<<adj[i].second.first<<" <-----> "<<adj[i].second.second<<endl;
            cost += adj[i].first;
            union1(adj[i].second.first, adj[i].second.second, idx);
        }
    }
    cout<<cost;
}

int partitionQS(vector<pair<int, pair<int, int> > >&adj, int s, int e){
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

void quickSort(vector<pair<int, pair<int, int> > >&adj, int s, int e){
    if(s<e){
        int i = partitionQS(adj, s, e);
        quickSort(adj, s, i-1);
        quickSort(adj, i+1, e);
    }
}

int main(){
    vector<pair<int, pair<int, int> > >adj;
    int v, e;
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int src, dest, wt;
        cin>>src>>dest>>wt;
        adj.push_back((make_pair(wt, make_pair(src, dest))));
    }
    int idx[v];
    for(int i=0;i<v;i++)
        idx[i] = i;
    quickSort(adj, 0, e-1);
    /*for(int i=0;i<v;i++){
        cout<<adj[i].first<<" "<<adj[i].second.first<<" "<<adj[i].second.second<<endl;
    }*/
    //sort(adj.begin(), adj.end());
    KrushkalMST(adj, v, e, idx);
}
