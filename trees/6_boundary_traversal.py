from starter_tree_code import Node,BinaryTree



def isLeaf(node):
    if not node.left and not node.right:
        return True
    
    return False

def left_boundary(root,res):
    curr=root.left
    while curr:
        if not isLeaf(curr):
            res.append(curr.data)
        if curr.left:
            curr=curr.left
        else:
            curr=curr.right


def right_boundary(root,res):
    curr=root.right
    temp=[]
    while curr:
        if not isLeaf(curr):
            temp.append(curr.data)
        if curr.right:
            curr=curr.right
        else:
            curr=curr.left
    temp.reverse()
    for num in temp:
        res.append(num)

def add_leaves(root,res):
    if isLeaf(root):
        res.append(root.data)

    if root.left:
        add_leaves(root.left,res)        

    if root.right:
        add_leaves(root.right,res)




def boundaryTraversal(root):
    # Code here
    res=[]
    if not root:
        return res
    
    if not isLeaf(root):
        res.append(root.data)

    left_boundary(root,res)
    add_leaves(root,res)
    right_boundary(root,res)

    return res

    


values=[1,2,3,4,5,6,7]
# values=[1,2,3,None,None,None,4]
# values=[1,2,7,3,None,None,8,None,4,9,None,5,6,10,11]
tree=BinaryTree(values)
root=tree.root

ans=boundary_traversal(root)

print(ans)