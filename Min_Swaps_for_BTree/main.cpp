#include<bits/stdc++.h>
using namespace std;

void inorder(int arr[], vector<int> &v, int cur, int n){
    if(cur >= n)
        return;
    inorder(arr, v, 2*cur+1, n);
    v.push_back(arr[cur]);
    inorder(arr, v, 2*cur+2, n);
}

void minSwaps(vector<int> v){
    vector<pair<int, int> >adj(v.size());
    for(int i=0;i<adj.size();i++){
        adj[i].first = v[i];
        adj[i].second = i;
    }
    sort(adj.begin(), adj.end());
    int c = 0;
    for(int i=0;i<adj.size();i++){
        if(adj[i].second == i){
            continue;
        }
        else{
            swap(adj[i].first, adj[adj[i].second].first);
            swap(adj[i].second, adj[adj[i].second].second);
        }
        if(i != adj[i].second){
            --i;

        }
        c++;
    }
    cout<<c;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> v;
    inorder(arr, v, 0, n);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    minSwaps(v);
}

/*
<8, 0>
<6, 1>
<9, 2>
<5, 3>
<10, 4>
<7, 5>
<11, 6>

<5, 3>   <8, 0>
<6, 1>
<7, 5>   <9, 2>
<8, 0>   <5, 3>
<9, 2>   <7, 5>
<10, 4>
<11, 6>

*/
