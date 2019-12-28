#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;
int n, m, adj[1000001][1000001];

int getMinIdx(bool vis[], int dist[]){
    int minVal = INT_MAX, minIdx = 0;
    for(int i=1;i<=n;i++){
        if(dist[i]<=minVal && vis[i] == false){
            minVal = dist[i];
            minIdx = i;
        }
    }
    return minIdx;
}

void dijkstra(int src){
    bool vis[n+1];
    memset(vis, false, sizeof(vis));
    int dist[n+1];
    for(int i=0;i<=n;i++){
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    for(int i=1;i<=n;i++){
        int minIdx = getMinIdx(vis, dist);
        vis[minIdx] = true;
        for(int j=1;j<=n;j++){
            if(adj[minIdx][j] != 0 && !vis[j] && dist[minIdx] != INT_MAX && dist[j] > dist[minIdx] + adj[minIdx][j]){
                dist[j] = dist[minIdx] + adj[minIdx][j];
            }
        }
    }
    for(int i=2;i<=n;i++)
        cout<<dist[i]<<" ";
}

int main(){
    cin>>n>>m;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            adj[i][j] = 0;
    for(int i=0;i<m;i++){
        int x, y, w;
        cin>>x>>y>>w;
        adj[x][y] = w;
        adj[y][x] = w;
    }
    dijkstra(1);
}
