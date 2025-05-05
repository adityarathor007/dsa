from collections import deque

# dfs
def dfs(graph,node,visited):
    visited[node-1]=1
    print(node)

    for neighbor in graph[node]:
        if visited[neighbor-1]==0:
            dfs(graph,neighbor,visited)




def dfs_iterative(graph,node,visited):
    stack=[node]

    while stack:
        node=stack.pop()
        visited[node-1]=1
        print(node)

        for neighbor in reversed(graph[node]):
            if visited[neighbor-1]==0:
                stack.append(neighbor)




# bfs
def bfs(graph,node,visited):
    queue=deque()
    queue.append(node)


    while queue:
        current_node=queue.popleft()
        visited[current_node-1]=1
        print(current_node)

        for neighbor in graph[current_node]:
            if visited[neighbor-1]==0:
                queue.append(neighbor)



if __name__=="__main__":

    graph={
        1:[2,5],
        2:[1,3,6],
        3:[2,4],
        4:[3],
        5:[1],
        6:[2]
    }

    n=len(graph)
    # print(n)
    visited=[0]*n

    print("with recursive dfs")
    dfs(graph,1,visited)

    visited=[0]*n

    print("with iterative dfs")
    dfs_iterative(graph,1,visited)

    # visited=[0]*n
    # bfs(graph,1,visited)
