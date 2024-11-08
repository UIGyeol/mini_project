class Node:
    def __init__(self,data,link):
        self.data=data
        self.link=link

class LinkedStack:
    def __init__(self):
        self.top=None
    
    def isEmpty(self):
        return self.top==None
    
    def push(self,data):
        self.top=Node(data,self.top)
    
    def pop(self):
        if not self.isEmpty():
            n=self.top.data
            self.top=self.top.link
            return n
        else:
            print("Empty")
    
    def peek(self):
        if not self.isEmpty():
            return self.top.data
        
    def size(self):
        node=self.top
        count=0
        while not node==None:
            count+=1
            node=node.link
        return count
    
    def __str__(self):
        arr=[]
        node=self.top
        while not node==None:
            arr.append(node.data)
            node=node.link
        return str(arr)
    
stack=LinkedStack()
print(f"스택 : {stack}")
string1=input("문자열 입력: ")

for i in string1:
    stack.push(i)

print(f"스택 : {stack}")

print(f"문자열 출력: {stack}")

while not stack.isEmpty():
    print(stack.pop(),end=" ")

print(f"스택 : {stack}")
