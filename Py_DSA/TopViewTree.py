class Node:
    def __init__(self, key):
        self.data = key
        self.lchild = None
        self.rchild = None
        self.topCount = 0

def topViewTree(root):
    queue = []
    queue.append(root)
    dTree = dict()
    tCount = 1
    root.topCount = tCount
    while(len(queue)):
        temp = queue[0]
        tCount = temp.topCount
        if tCount not in dTree:
            dTree[tCount] = temp.data
        if(temp.lchild):
            temp.lchild.topCount = tCount -1
            queue.append(temp.lchild)
        if(temp.rchild):
            temp.rchild.topCount = tCount +1
            queue.append(temp.rchild)
        queue.pop(0)
    
    for i in sorted(dTree):
        print(dTree[i])

def preOrder(root):
    if root is not None:
        print(root.data)
        preOrder(root.lchild)
        preOrder(root.rchild)

if __name__ == "__main__":
    root = Node(1)  
    root.lchild = Node(2)
    root.rchild = Node(3)
    root.lchild.lchild = Node(4)  
    root.lchild.rchild = Node(5)
    root.rchild.lchild = Node(6)
    root.rchild.rchild = Node(7)  
    #preOrder(root)
    topViewTree(root)