from collections import deque

class Node():
    def __init__(self,val):
        self.val=val
        self.left=None
        self.right=None


class BinaryTree:
    def __init__(self,values):

        if not values:
            self.root=None
            return 

        self.root=Node(values[0])
        queue=deque([self.root])

        i=1
        while i<len(values):
            
            node=queue.popleft()
            
            if i<len(values) and values[i] is not None:
                node.left=Node(values[i])
                queue.append(node.left)

            i+=1


            if i<len(values) and values[i] is not None:
                node.right=Node(values[i])
                queue.append(node.right)

            i+=1
