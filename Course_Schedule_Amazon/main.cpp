/*
There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
For example:
2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
*/

#include<bits/stdc++.h>
using namespace std;


bool dfs(vector<int> g[], vector<int> &vis, int i){
    if(vis[i] == 1){
        return true;
    }
    vis[i] = -1;
    for(int j=0;j<g[i].size(); j++){
        if(vis[g[i][j]] == -1 || !dfs(g, vis, g[i][j]))
            return false;
    }
    vis[i] = 1;
    return true;
}

bool canPass(vector<pair<int, int> >&adj, int n, int m){
    vector<int> vis(n, 0);
    //vector<set<int> > g(n);
    vector<int> g[n];
    for(int i=0;i<m;i++){
        g[adj[i].second].push_back(adj[i].first);
    }
    /*
    vector<int>:: iterator j;
    for(int i=0;i<n;i++){
        cout<<i<<" ";
        for(j=g[i].begin(); j!=g[i].end();j++){
            cout<<*j<<" ";
        }
        cout<<endl;
    }*/

    for(int i=0;i<n;i++){
        if(!dfs(g, vis, i))
            return false;
    }
    return true;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<pair<int, int> >adj;
    int x, y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        adj.push_back(make_pair(x, y));
    }
    if(canPass(adj, n, m))
        cout<<"Yes He can complete";
    else
        cout<<"Ganta";
}
/*
7 7
0 1
1 2
2 3
0 4
0 5
5 6
5 2
*/
