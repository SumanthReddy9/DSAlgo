class Graph:
    def __init__(self, V):
        self.V = V
        self.adj = [[] for i in range(V)]
    
    def addEdge(self, u, v):
        self.adj[u].append(v)
    
    def BFSUtill(self, v, vis):
        queue = []
        queue.append(v)
        vis[v] = True
        while(len(queue)):
            s = queue.pop(0)
            print(s)

            for i in self.adj[s]:
                if vis[i] == False:
                    queue.append(i)
                    vis[i] = True

    def BFS(self, s):
        vis = [False]*(len(self.adj))

        self.BFSUtill(s, vis)
    
g = Graph(4)

g.addEdge(0, 1) 
g.addEdge(0, 2) 
g.addEdge(1, 2) 
g.addEdge(2, 0) 
g.addEdge(2, 3) 
g.addEdge(3, 3) 

g.BFS(2)