from collections import deque

# use something and return something else
# Finding diameter of tree
# Finding max possible between 2 nodes joined by an edge i.e path exists between them

class Node:
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

def findDiameter(node,diameter):
    
    if not node:
        return 0

    lh=findDiameter(node.left,diameter)
    rh=findDiameter(node.right,diameter)

    height_w_currentNode=lh+rh
    
    if height_w_currentNode>diameter[0]:
        print(node.val)
        diameter[0]=height_w_currentNode
    

    return 1+max(lh,rh)


def findMaxSumPath(node,maxSum):
    # maxSum: contains the best sum possible

    if node is None:
        return 0
    
    ls=max(0,findMaxSumPath(node.left,maxSum))
    rs=max(0,findMaxSumPath(node.right,maxSum))

    cs=ls+rs+node.val
    
    if cs>maxSum[0]:
        maxSum[0]=cs
    
    return node.val+max(ls,rs)


    





# values = [1, 2, 3, None, 4, 5, 6]  # adding nodes level wise
# values=[1,2,None,3,4,4,None,5,None,None,None,6]

values=[-10,9,20,None,None,15,7]
tree = BinaryTree(values)


# diameter=[-1]
# findDiameter(tree.root,diameter)
# print(diameter[0])


maxSum=[float('-inf')]

findMaxSumPath(tree.root,maxSum)
print(maxSum[0])


