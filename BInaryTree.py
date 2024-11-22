class Node:
    def __init__(self,data,left,right):
        self.data=data
        self.right=right
        self.left=left

def preorder(n):
    if n is not None:
        print(n.data,end=' ')
        preorder(n.left)
        preorder(n.right)

def inorder(n):
    if n is not None:
        inorder(n.left)
        print(n.data,end=' ')
        inorder(n.right)

def postorder(n):
    if n is not None:
        inorder(n.left)
        inorder(n.right)
        print(n.data,end=' ')
       

b=Node("B",None,None)
c=Node("C",None,None)
root=Node("A",b,c)
preorder(root)
print("")
inorder(root)
print("")
postorder(root)
