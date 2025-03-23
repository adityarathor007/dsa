# Finding Height of binary tree
# Check if the tree is height balanced or not

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
            new_node.left=current_node.left
            current_node.left=new_node
    
    def insert_right(self,current_node,key):
        if current_node.right is None:
            current_node.right=Node(key)
        
        else:
            new_node=Node(key)
            new_node.right=current_node.right
            current_node.right=new_node




def findHeight(root):
    if not root:
        return 0
    
    return 1+max(findHeight(root.left),findHeight(root.right))


def checkHeightBalance(root):
    
    # Brute Force Solution O(N*N)
    # if not root:
    #     return True

    # left_height=findHeight(root.left)
    # right_height=findHeight(root.right)
    
    # if abs(left_height-right_height)>1:
    #     print(root.key)
    #     return False

    # return checkHeightBalance(root.left) and checkHeightBalance(root.right)

    # inspired by calculating the height of binary tree (O(N))

    #OUTPUT: return -1 if not a balanced tree or returns the height

    if not root:
        return 0

    lh=checkHeightBalance(root.left)
    rh=checkHeightBalance(root.right)

    if (lh==-1 or rh==-1):
        return -1
    
    if(abs(lh-rh)>1):
        return -1

    return 1+max(lh,rh)
    



if __name__=="__main__":
    
    # intialization 
    tree=BinaryTree(1)
    root=tree.root
    tree.insert_left(root,2)
    tree.insert_right(root,3)
    tree.insert_left(root.left,4)
    tree.insert_right(root.right,5)
    tree.insert_right(root.right.right,6)

    # finding height
    # print(findHeight(root))


    # checking if tree is height balanced or not
    print(checkHeightBalance(root))
