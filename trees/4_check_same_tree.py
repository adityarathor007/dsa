class TreeNode():
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


def isSameTree(p,q):
    # more elaborative
    # if p is None and q is None:
    #     return True
    # elif p is None or q is None:
    #     return False
    
    # if p.val!=q.val:
    #     return False

    # return isSameTree(p.left,q.left) and isSameTree(p.right,q.right)



    # more concise
    if p is None or q is None:
        return p==q #i.e checks if both are null or either of is null
    
    return p.val==q.val and isSameTree(p.left,q.left) and isSameTree(p.right,q.right)
