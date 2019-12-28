#include<bits/stdc++.h>
using namespace std;

int arr[10][10];
int timeVal = 0;

void dfs(int arr[][10], int n, bool vis[], int i){
    vis[i] = true;
    for(int j=0;j<n;j++){
        if(arr[i][j] == 1 && !vis[j]){
            dfs(arr, n, vis, j);
        }
    }
}

void getArtPointsBF(int arr[][10], int n, int m){
    bool vis[n];
    memset(vis, false, sizeof(vis));
    int initVal = 0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(arr, n, vis, i);
            initVal++;
        }
    }
    int c = 0;
    int copyArr[n];
    for(int i=0; i<n; i++){
        for(int j=0;j<n;j++){
            vis[j] = false;
            copyArr[j] = arr[i][j];
            arr[i][j] = arr[j][i] = 0;
        }
        int nval = 0;
        for(int j=0;j<n;j++){
            if(j != i && !vis[j]){
                nval++;
                dfs(arr, n, vis, j);
            }
        }
        if(nval > initVal){
            c++;
        }
        for(int j=0;j<n;j++)
            arr[i][j] = arr[j][i] = copyArr[j];
    }
    cout<<c<<endl;
}


void getArtPointsDFS(int v, bool vis[], int disc[], int low[], int parent[], bool AP[], int n){
    vis[v] = true;
    disc[v] = low[v] = timeVal++;
    int child = 0;
    for(int i=0;i<n;i++){
        if(arr[v][i] == 1){
            if(!vis[i]){
                child++;
                parent[i] = v;
                getArtPointsDFS(i, vis, disc, low, parent, AP, n);
                low[v] = min(low[v], low[i]);
                if(child > 1 && parent[v] == -1){
                    AP[v] = true;
                }
                if(parent[v] != -1 && low[i] >= disc[v]){
                    AP[v] = true;
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
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j] = 0;
        }
    }
    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        arr[x][y] = arr[y][x] = 1;
    }
    getArtPointsBF(arr, n, m);
    int disc[n], low[n], parent[n];
    bool vis[n], AP[n];
    memset(disc, 0, sizeof(disc));
    for(int i=0;i<n;i++)
    {
        parent[i] = -1;
        low[i] = INT_MAX;
        vis[i] = false;
        AP[i] = false;
    }
    for(int i=0;i<n;i++){
        if(!vis[i])
            getArtPointsDFS(i, vis, disc, low, parent, AP, n);
    }
    int c = 0;
    for(int i=0;i<n;i++){
        if(AP[i] == true){
            c++;
        }
    }
    cout<<c<<endl;
}
