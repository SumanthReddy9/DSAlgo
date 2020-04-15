#include<bits/stdc++.h>
using namespace std;

int arr[100][100];
int dis[100][100];
bool vis[100][100];
int n, m;
string pat = "DLRU";
int arrx[] = {1, 0, 0, -1};
int arry[] = {0, -1, 1, 0};

bool isSafe(int x, int y){
    if(x >= 0 && y >= 0 && x < n && y < m && arr[x][y] == 1){
        return true;
    }
    return false;
}

void getPaths(int ax, int ay, int bx, int by){
    memset(dis, 0, sizeof(dis));
    memset(vis, false, sizeof(vis));
    queue<pair<int, int> > q;
    q.push(make_pair(bx, by));
    vis[bx][by] = true;
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int curx = cur.first + arrx[i];
            int cury = cur.second + arry[i];
            if(isSafe(curx, cury) && !vis[curx][cury]){
                vis[curx][cury] = true;
                dis[curx][cury] = dis[cur.first][cur.second] + 1;
                q.push(make_pair(curx, cury));
            }
        }
    }

    if(vis[ax][ay] == false){
        cout<<"Impossible";
    }
    else{
        string ans;
        while(1){
            if(ax == bx && ay == by){
                cout<<ans<<endl;
                break;
            }
            for(int i=0;i<4;i++){
                if(dis[ax][ay] == dis[ax+arrx[i]][ay+arry[i]] + 1 && isSafe(ax+arrx[i], ay+arry[i])){
                    ans += pat[i];
                    ax += arrx[i];
                    ay += arry[i];
                    break;
                }
            }
        }
        /*string ans;
        while(1){
            if(ax == bx && ay == by){
                cout<<ans<<endl;
                break;
            }
            for(int i=0;i<4;i++){
                if(dis[ax][ay] == dis[ax+arrx[i]][ay+arry[i]] + 1 && isSafe(ax+arrx[i], ay+arry[i])){
                    ans += pat[i];
                    ax += arrx[i];
                    ay += arry[i];
                    break;
                }
            }
        }*/
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        for(int j=0;j<m;j++){
            if(str[j] == '.'){
                arr[i][j] = 1;
            }
            else{
                arr[i][j] = 0;
            }
        }
    }
    int q;
    cin>>q;
    while(q--){
        int ax, ay, bx, by;
        cin>>ax>>ay>>bx>>by;
        getPaths(ax-1,ay-1, bx-1, by-1);
    }
}
