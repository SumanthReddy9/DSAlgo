#include<bits/stdc++.h>
using namespace std;

struct node{
    int d, w;
};

void addEdge(vector<node>adj[], int u, int v, int w){
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

void BFS(vector<node>adj[], int src, int dest, int n, int pred[], int dist[]){
    bool vis[n];
    for(int i=0;i<n;i++){
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
    memset(vis, false, sizeof(vis));
    vis[src] = true;
    queue<int>q;
    q.push(src);
    dist[src] = 0;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(int i=0;i<adj[top].size(); i++){
            if(dist[adj[top][i].d] > dist[top] + adj[top][i].w){
                dist[adj[top][i].d] = dist[top] + adj[top][i].w;
                pred[adj[top][i].d] = top;
                //vis[adj[top][i].d] = true;
                q.push(adj[top][i].d);
                /*if(dest == adj[top][i].d){
                    return true;
                }*/
            }
        }
    }
    //return false;
}

void getMinPath(vector<node>adj[], int s, int d, int n){
    int pred[n], dist[n];
    BFS(adj, s, d, n, pred, dist);
    vector<int>path;
    int crawl = d;
    while(pred[crawl] != -1){
        path.push_back(crawl);
        crawl = pred[crawl];
    }
    cout<<"Shortest Distance is: "<<dist[d]<<endl;
    for(int i=path.size()-1;i>=0;i--){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}

int main(){
    /*int n, e;
    cin>>n>>e;
    vector<node>adj[n];
    for(int i=0;i<e;i++){
        int u, v, w;
        cin>>u>>v>>w;
        addEdge(adj, u, v, w);
    }
    int s, d;
    cin>>s>>d;
    getMinPath(adj, s, d, n);*/
    vector<node>graph[9];
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);
    for(int i=1;i<9;i++)
        getMinPath(graph, 0, i, 9);
}


/*8
10
1 2 2
1 0 2
0 3 2
3 7 2
3 4 2
7 4 2
7 6 2
4 6 2
5 6 2
4 5 2*/

