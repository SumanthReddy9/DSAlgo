#include<bits/stdc++.h>
#define v 5
using namespace std;

bool isSafe(int g[v][v], int i, int path[], int pos){
    if(g[path[pos-1]][i] == 0)
        return false;
    for(int j=0;j<pos;j++){
        if(path[j] == i)
            return false;
    }
    return true;
}

bool hamCycleU(int g[v][v], int &flag, int path[], int pos){
    if(pos == v){
        if(g[path[pos-1]][path[0]] == 1)
            return true;
        else
            return false;
    }
    for(int i=1;i<v;i++){
        if(isSafe(g, i, path, pos)){
            path[pos] = i;
            if(hamCycleU(g, flag, path, pos+1) == true)
            {
                for(int i=0;i<v;i++){
                    cout<<path[i]<<" ";
                }
                cout<<path[0]<<endl;
                flag = 1;
            }
            path[pos] = -1;
        }
    }
    return false;
}

void hamCycle(int g[v][v]){
    int path[v];
    memset(path, -1, sizeof(path));
    path[0] = 0;
    int flag = 0;
    if(hamCycleU(g, flag, path, 1) == false && flag == 0){
        cout<<"Not possible NIGGA";
    }
}


int main(){
    int g[v][v] =
    {{0, 1, 1, 0, 1},
    {1, 0, 1, 1, 1},
    {1, 1, 0, 1, 0},
    {0, 1, 1, 0, 1},
    {1, 1, 0, 1, 0}};
    int path[v];
    memset(path, -1, sizeof(path));
    hamCycle(g);
}
