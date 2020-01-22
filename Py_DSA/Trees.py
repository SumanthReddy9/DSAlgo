class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

def insert(root, node):
    if root.val > node.val:
        if root.left is None:
            root.left = node
        else:
            insert(root.left, node)
    else:
        if root.right is None:
            root.right = node
        else:
            insert(root.right, node)


def preOrder(root):
    if root is not None:
        print(root.val)
        preOrder(root.left)
        preOrder(root.right)

n = int(input())
arr = list(map(int, input().strip().split()))
root = None
for i in arr:
    if root is None:
        root = Node(i)
    else:
        insert(root, Node(i))
preOrder(root)
    

