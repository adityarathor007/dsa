# create a tree from scratch
# all traversal via iterative and recursion

from collections import deque

class Node:
    def __init__(self,key):
        self.key=key
        self.left=None
        self.right=None
    
class BinaryTree:
    def __init__(self,root_key):
        
        self.root=Node(root_key)
    
    def insert_left(self,current_node,key):
        if current_node.left is None:
            current_node.left=Node(key)
        
        else:
            new_node=Node(key)
            new_node.left=current_node.left #inserting b/w current_node and its left
            current_node.left=new_node

    def insert_right(self,current_node,key):
        
        if current_node.right is None:
            current_node.right=Node(key)
        else:
            new_node=Node(key)
            new_node.right=current_node.right
            current_node.right=new_node


    # DFS methods
    def preorder_traversal(self,node): #(P,L,R)
        
        # recursive method
        if node:
            print(node.key,end=" ")
            self.preorder_traversal(node.left)
            self.preorder_traversal(node.right)

        # iterative method
        # if not node:
        #     return
        
        # stack=deque()
        # stack.append(node)

        # while stack:
        #     current_node=stack.pop()
        #     print(current_node.key,end=" ")

        #     if current_node.right:
        #         stack.append(current_node.right)

        #     if current_node.left: 
        #         stack.append(current_node.left)
            



    def inorder_traversal(self,node): #(L,P,R)
        
        
        # recursive method
        if node:
            self.inorder_traversal(node.left)
            print(node.key,end=" ")
            self.inorder_traversal(node.right)

        # iterative method

        # stack=deque()
        # current=node
        # while current or stack:
        #     while current:
        #         stack.append(current.left)
        #         current=current.left
            
        #     current=stack.pop()
            
        #     print(current.key,end=" ")
            
        #     current=current.right


    
    def postorder_traversal(self,node): #(L,R,P)
        if node:
            self.postorder_traversal(node.left)
            self.postorder_traversal(node.right)
            print(node.key,end=" ")

    
    def postorder_traversal_using2stack(self,node):
    
        stack1=deque()
        stack2=deque()
        current=node
        if node is None:
            return
        stack1.append(node)
        while stack1:
            root=stack1.pop()
            stack2.append(root)

            if root.left:
                stack1.append(root.left)
            if root.right:
                stack1.append(root.right)
        
        while stack2:
            current=stack2.pop()
            print(current.key,end=" ")
        
    def postorder_traversal_using1stack(self,node):
        stack=deque()
        current=node
        traversal=[]
        while current or stack:
            if current:
                stack.append(current)
                current=current.left
            else:
                temp=stack[-1].right
                if not temp: #means the top of stack is a leaf node
                    temp=stack.pop()
                    traversal.append(temp.key)
                    while(stack and temp==stack[-1].right):
                        temp=stack.pop()
                        traversal.append(temp.key)
                else:
                    current=temp

        return traversal


            
        


    # bfs method
    def level_order_traversal(self):
        if not self.root:
            return 
        queue=deque([self.root])
        while queue:
            node=queue.popleft()
            print(node.key,end=" ")
            
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)







bt=BinaryTree(1)
bt.insert_left(bt.root,2)
bt.insert_right(bt.root,3)
bt.insert_left(bt.root.left,4)
bt.insert_right(bt.root.left,5)


print("Preorder Traversal: ")
bt.preorder_traversal(bt.root)
print("\n")

print("Inorder Traversal: ")
bt.inorder_traversal(bt.root)
print("\n")

print("Postorder Traversal: ")
bt.postorder_traversal(bt.root)
print("\n")

print("Levelorder Traversal")
bt.level_order_traversal()
print("\n")


print("PostOrder traversal using 2 stacks: ")
bt.postorder_traversal_using2stack(bt.root)
print("\n")

print("Postorder Traversal (Iterative with One Stack):")
print(bt.postorder_traversal_using1stack(bt.root))