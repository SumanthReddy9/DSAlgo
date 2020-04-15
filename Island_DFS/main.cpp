#include<bits/stdc++.h>
#define r 7
#define c 5
using namespace std;

bool isValid(int x, int y){
    if((x >= 0 && y >= 0) && (x < r && y <c))
        return true;
    return false;
}

void DFS(int arr[][c], bool vis[][c], int i, int j){
    vis[i][j] = true;
    int x[] = {1, 1, 1, 0, -1, -1, -1, 0};
    int y[] = {1, 0, -1, -1, -1, 0, 0, 1};
    for(int k=0;k<8;k++){
        if(isValid(i+x[k], j + y[k]) &&  !vis[i+x[k]][j+y[k]] && arr[i+x[k]][j+y[k]]){
            DFS(arr, vis, i+x[k], j+y[k]);
        }
    }
}

void getIsland(int arr[][c]){
    bool vis[r][c];
    memset(vis, false, sizeof(vis));
    int countIsland = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(!vis[i][j] && arr[i][j]){
                DFS(arr, vis, i, j);
                countIsland++;
            }
        }
    }
    cout<<countIsland;
}


int main(){
    int arr[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
        }
    }
    getIsland(arr);
}
