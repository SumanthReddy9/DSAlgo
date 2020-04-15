#include<bits/stdc++.h>
#define v 5
using namespace std;

bool isSafe(int g[v][v], int path[], int pos, int i){
    if(g[path[pos-1]][i] == 0)
        return false;
    for(int j=0;j<pos;j++){
        if(path[j] == i){
            return false;
        }
    }
    return true;
}

bool hamCycleU(int g[v][v], int path[], int &flag, int pos){
    if(pos == v){
        if(g[path[pos-1]][path[0]] == 1){
            return true;
        }
        else{
            return false;
        }
    }
    for(int i=0;i<v;i++){
        if(isSafe(g, path, pos, i)){
            path[pos] = i;
            if(hamCycleU(g, path, flag, pos+1)){
                for(int j=0;j<v;j++){
                    cout<<path[j]<<"   ";
                }
                cout<<path[0]<<" ";
                cout<<endl;
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
    if(hamCycleU(g, path, flag, 1) == false && flag == 0){
        cout<<"Not Possible Nibba";
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
