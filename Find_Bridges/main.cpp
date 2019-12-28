#include<bits/stdc++.h>
using namespace std;
int arr[10][10];
int timeVal = 0;

void dfs(int v, int disc[], int low[], bool vis[], int parent[], int n){
    vis[v] = true;
    disc[v] = low[v] = timeVal++;
    for(int i=0;i<n;i++){
        if(arr[v][i] == 1){
            if(!vis[i]){
                parent[i] = v;
                dfs(i, disc, low, vis, parent, n);
                low[v] = min(low[v], low[i]);
                if(low[i] > disc[v]){
                    cout<<i<<"   "<<v<<endl;
                }
            }
            else if(parent[v] != i){
                low[v] = min(low[v], disc[i]);
            }
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j] = 0;
    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        arr[x][y] = arr[y][x] = 1;
    }
    int disc[n], low[n], parent[n];
    bool vis[n];
    memset(vis, false, sizeof(vis));
    memset(disc, 0, sizeof(disc));
    for(int i=0;i<n;i++){
        parent[i] = -1;
        low[i] = INT_MAX;
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i, disc, low, vis, parent, n);
        }
    }
}
