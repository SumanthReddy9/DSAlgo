#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int x, int y){
    adj[x].push_back(y);
    adj[y].push_back(x);
}

int bfs(vector<int> adj[], int l, int n, int src){
    bool vis[n+1];
    memset(vis, false, sizeof(vis));
    queue<int>q;
    q.push(src);
    int level = 0;
    while(!q.empty()){
        int s = q.size();
        level++;
        if(level == l){
            return s;
        }
        else{
            for(int i=0;i<s;i++){
                int cur = q.front();
                vis[cur] = true;
                q.pop();
                for(int j=0;j<adj[cur].size();j++){
                    if(!vis[adj[cur][j]])
                        q.push(adj[cur][j]);
                }
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> adj[n+1];
    for(int i=1;i<n;i++){
        int x, y;
        cin>>x>>y;
        addEdge(adj, x, y);
    }
    int l;
    cin>>l;
    cout<<bfs(adj, l, n, 1);
}
