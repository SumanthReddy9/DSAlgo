#include<bits/stdc++.h>
#define v 9
using namespace std;

int getminidx(int dist[], bool vis[]){
    int minidx, minVal = INT_MAX;
    for(int i=0;i<v;i++){
        if(!vis[i] && dist[i] <= minVal){
            minidx = i;
            minVal = dist[i];
        }
    }
    return minidx;
}

void dijkstra(int adj[v][v], int src){
    bool vis[v];
    memset(vis, false, sizeof(vis));
    int pred[v], dist[v];
    pred[src] = -1;
    for(int i=0;i<v;i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    vector<int> path[v];
    int c = v;
    while(c--){
        int minIdx = getminidx(dist, vis);
        vis[minIdx] = true;
        for(int i=0;i<v;i++){
            if(adj[minIdx][i] && dist[minIdx] != INT_MAX && dist[i] > dist[minIdx] + adj[minIdx][i] && !vis[i]){
                dist[i] = dist[minIdx] + adj[minIdx][i];
                pred[i] = minIdx;
            }
        }
    }
    for(int i=0;i<v;i++){
        int crawl = i;
        while(pred[crawl] != -1){
            path[i].push_back(crawl);
            crawl = pred[crawl];
        }
        cout<<src<<" ";
        for(int j=path[i].size()-1; j >= 0; j--){
            cout<<path[i][j]<<" ";
        }
        cout<<"------>"<<dist[i];
        cout<<endl;
    }
}

int main(){
    int e;
    cin>>e;
    int adj[v][v];
    memset(adj, 0, sizeof(adj));
    for(int i=0;i<e;i++){
        int x, y, w;
        cin>>x>>y>>w;
        adj[x][y] = w;
        adj[y][x] = w;
    }

    /*int adj[v][v] = {
            { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
            { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
            { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
            { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
            { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
            { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
            { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
            { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
            { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
            };*/
    dijkstra(adj, 0);
}

/*
14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 8 6
6 7 1
7 8 7
*/
