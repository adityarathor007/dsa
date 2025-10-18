from starter_tree_code import Node,BinaryTree
from collections import deque



def vertical_traversal(root):
    ans=[]
    if not root:
        return ans
    
    queue=deque()
    queue.append((root,0))
    dict={}
    while queue:
        size=len(queue)
        for i in range(size):
            node,vl=queue.popleft()
            if node.left:
                queue.append((node.left,vl-1))
            if node.right:
                queue.append((node.right,vl+1))

            if vl in dict:
                dict[vl].append(node.val)
            else:
                dict[vl]=[node.val]


    # converting dict to list
    sorted_keys=sorted(dict.keys())
    result=[dict[key] for key in sorted_keys]
    return result
            


values=[2,7,5,2,6,None,9,None,None,5,11,4]
tree=BinaryTree(values)
root=tree.root
ans=vertical_traversal(root)

for arr in ans:
    print(arr)




