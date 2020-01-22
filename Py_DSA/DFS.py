from collections import defaultdict
class Graph:
    def __init__(self, Ver):
        self.Ver = Ver
        self.adj = [[] for i in range(Ver)]

    def addEdge(self, u, v):
        self.adj[u].append(v)
    
    def printGraph(self):
        print(self.adj)
    
    def DFSUtill(self, v, vis):
        vis[v] = True
        
        print(v)

        for i in self.adj[v]:
            if vis[i] == False:
                self.DFSUtill(i, vis)

    def DFS(self):
        v = len(self.adj)
        vis = [False]*(v)

        for i in range(v):
            if vis[i] == False:
                self.DFSUtill(i, vis)

    def DFSSTK(self, s):
        v = len(self.adj)
        vis = [False]*(v)

        stack = []

        stack.append(s)

        while(len(stack)):
            s = stack[-1]
            stack.pop()

            if(vis[s] == False):
                print(s)
                vis[s] = True
            for i in self.adj[s]:
                if vis[i] == False:
                    stack.append(i)


g = Graph(5)

g.addEdge(1, 0)  
g.addEdge(0, 2)  
g.addEdge(2, 1) 
g.addEdge(0, 3)  
g.addEdge(1, 4)  

g.DFS()

#g.DFSSTK(0)