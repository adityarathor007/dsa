from starter_tree_code import Node,BinaryTree
from collections import deque


def zigzag_traversal(root):
    
    queue=deque()
    ans=[]
    queue.append(root)
    left_to_right=True
    
    while queue:
        size=len(queue)

        temp_list=[]
        
        for i in range(size):  #traversing the entire level
            node=queue.popleft()
            temp_list.append(node.val)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

        if not left_to_right:
            temp_list.reverse()
        
        ans.append(temp_list)
        left_to_right=not left_to_right

    

    return ans

      




            


        
    
        
