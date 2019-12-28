#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int>adj[], int x, int y){
    adj[x].push_back(y);
    adj[y].push_back(x);
}

void BFS(vector<int>adj[], int n, int s){
    bool vis[n+1];
    memset(vis, false, sizeof(vis));
    queue<int>q;
    q.push(s);
    vis[s] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout<<cur<<" ";
        for(int i=0;i<adj[cur].size();i++){
            if(!vis[adj[cur][i]]){
                vis[adj[cur][i]] = true;
                q.push(adj[cur][i]);
            }
        }
    }
}

void DFS(vector<int>adj[], int n, int s){
    bool vis[n+1];
    memset(vis, false, sizeof(vis));
    stack<int>stk;
    stk.push(s);
    vis[s] = true;
    while(!stk.empty()){
        int cur = stk.top();
        stk.pop();
        cout<<cur<<" ";
        for(int i=0;i<adj[cur].size();i++){
            if(!vis[adj[cur][i]]){
                vis[adj[cur][i]] = true;
                stk.push(adj[cur][i]);
            }
        }
    }
}

void DFSRU(vector<int>adj[], int i, bool vis[]){
    vis[i] = true;
    cout<<i<<" ";
    //vector<int>::iterator itr;
    for(int j = 0; j<adj[i].size(); j++){
        if(!vis[adj[i][j]]){
            DFSRU(adj, adj[i][j], vis);
        }
    }
}

void DFSR(vector<int>adj[], int n, int s){
    bool vis[n+1];
    memset(vis, false, sizeof(vis));
    DFSRU(adj, 1, vis);
}

void BFSRU(vector<int>adj[], queue<int>&q, bool vis[]){
    if(q.empty()){
        return;
    }
    int top = q.front();
    q.pop();
    cout<<top<<" ";
    for(int i=0;i<adj[top].size();i++){
        if(!vis[adj[top][i]]){
            vis[adj[top][i]] = true;
            q.push(adj[top][i]);
        }
    }
    BFSRU(adj, q, vis);
}

void BFSR(vector<int>adj[], int n, int s){
    bool vis[n+1];
    memset(vis, false, sizeof(vis));
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i] = true;
            q.push(i);
            BFSRU(adj, q, vis);
        }
    }
}

int main(){
    int n, e;
    cin>>n>>e;
    vector<int>adj[n+1];
    int x, y;
    for(int i=0;i<e;i++){
        cin>>x>>y;
        addEdge(adj, x, y);
    }
    BFS(adj, n, 1);
    cout<<endl;
    DFS(adj, n, 1);
    cout<<endl;
    DFSR(adj, n, 1);
    cout<<endl;
    BFSR(adj, n, 1);
    cout<<endl;
}
