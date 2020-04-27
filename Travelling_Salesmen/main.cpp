#include<bits/stdc++.h>
#define v 4
using namespace std;
int g1[100][100] = {
        { 0, 1, 2, 0, 8},
        { 1, 0, 3, 5, 6},
        { 2, 3, 0, 4, 0},
        { 0, 5, 4, 0, 7},
        { 8, 6, 0, 7, 0}
    };
int g[100][100] = {
        { 0, 1, 6, 4},
        { 1, 0, 5, 2},
        { 6, 5, 0, 3},
        { 4, 2, 3, 0},

    };
int vis_all = (1<<v)-1;
int state[v][(1<<v)-1];



bool isSafe(int path[], int i,int pos){
    if(g[path[pos-1]][i] == 0)
        return false;
    for(int j=0;j<pos;j++){
        if(path[j] == i)
            return false;
    }
    return true;
}

/*bool hamCycleU(int path[], int pos, int &ans){
    if(pos == v){
        if(g[path[pos-1]][path[0]])
            return true;
        else
            return false;
    }
    for(int i=0;i<v;i++){
        if(isSafe(path, i, pos)){
            path[pos] = i;
            if(hamCycleU(path, pos+1, ans) == true){
                int t = 0;
                for(int j=0;j<v-1;j++){
                    t += g[path[j]][path[j+1]];
                }
                t += g[path[pos]][path[0]];
                ans = min(t, ans);
            }
            path[pos] = -1;
        }
    }
    return false;
}*/

bool hamCycleU(int path[], int pos, int &ans){
    if(pos == v){
        if(g[path[pos-1]][path[0]]){
            return true;
        }
        else{
            return false;
        }
    }
    for(int i=0;i<v;i++){
        if(isSafe(path, i, pos)){
            path[pos] = i;
            if(hamCycleU(path, pos+1, ans) == true){
                int temp = 0;
                for(int j=0;j<v-1;j++){
                    temp += g[path[j]][path[j+1]];
                }
                temp += g[path[pos]][path[0]];
                ans = min(ans, temp);
            }
            path[pos] = -1;
        }
    }
    return false;
}
void hamCycle(){
    int path[v];
    memset(path, -1, sizeof(path));
    path[0] = 0;
    int ans = INT_MAX;
    if(hamCycleU(path, 1, ans) == false && ans == INT_MAX)
        cout<<"Not Possible";
    else
        cout<<ans<<endl;
}

/*void tsp(vector<bool>&vis, int curPos, int curNum, int cost, int &ans){
    if(curNum == v && g[curPos][0]){
        ans = min(ans, cost + g[curPos][0]);
        return;
    }
    for(int i=0;i<v;i++){
        if(!vis[i] && g[curPos][i]){
            vis[i] = true;
            tsp(vis, i, curNum+1, cost + g[curPos][i], ans);
            vis[i] = false;
        }
    }
}*/

void tsp(vector<bool>&vis, int curPos, int curNum, int cost, int &ans){
    if(curNum == v && g[curPos][0]){
        ans = min(ans, cost + g[curPos][0]);
        return;
    }
    for(int i=0;i<v;i++){
        if(!vis[i] && g[curPos][i]){
            vis[i] = true;
            tsp(vis, i, curNum+1, cost + g[curPos][i], ans);
            vis[i] = false;
        }
    }
}

int cost = INT_MAX;

int tspDP(int mask, int pos){
    if(mask == vis_all){
        return g[pos][0];
    }
    if(state[pos][mask] != INT_MAX){
        return state[pos][mask];
    }
    for(int i=0;i<v;i++){
        if((mask & (1<<i)) == 0){
            int tempAns = g[pos][i] + tspDP((mask | (1<<i)), i);
            state[pos][mask] = min(state[pos][mask], tempAns);
        }
    }
    return state[pos][mask];
}
int main(){
    hamCycle();
    int n = v;
    vector<bool>vis(n);
    for(int i=0;i<n;i++){
        vis[i] = false;
    }
    vis[0] = true;
    int ans = INT_MAX;
    tsp(vis, 0, 1, 0, ans);
    cout<<ans<<endl;
    for(int i=0;i<v;i++){
        for(int j=0;j<(1<<v)-1;j++){
            state[i][j] = INT_MAX;
        }
    }
    cout<<tspDP(1, 0);
}
