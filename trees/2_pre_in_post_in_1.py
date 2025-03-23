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
            new_node.left=current_node.left
            current_node.left=new_node
    
    def insert_right(self,current_node,key):
        if current_node.right is None:
            current_node.right=Node(key)
        
        else:
            new_node=Node(key)
            new_node.right=current_node.right
            current_node.right=new_node



def get_pre_in_post_in1(node):
    
    # recursive approach 
    # if node:
    #     _pre.append(node.key)
    #     get_pre_in_post_in1(node.left,_pre,_in,_post)
    #     _in.append(node.key)
    #     get_pre_in_post_in1(node.right,_pre,_in,_post)
    #     _post.append(node.key)

    # return _pre,_in,_post


    # iterative approach
    stack=deque()
    stack.append((root,1))
    _pre=[]
    _in=[]
    _post=[]
    while stack:
        current_node,num=stack.pop()
        if num==1:
            _pre.append(current_node.key)
            num+=1
            stack.append((current_node,num))
            if current_node.left:
                stack.append((current_node.left,1))
        elif num==2:
            _in.append(current_node.key)
            num+=1
            stack.append((current_node,num))
            if current_node.right:
                stack.append((current_node.right,1))
        elif num==3:
            _post.append(current_node.key)

    return _pre,_in,_post









tree=BinaryTree(1)
root=tree.root
tree.insert_left(root,2)
tree.insert_right(root,3)


_pre=[]
_in=[]
_post=[]
# get_pre_in_post_in1(root,_pre,_in,_post)
_pre,_in,_post=get_pre_in_post_in1(root)


print(_pre)
print(_in)
print(_post)


