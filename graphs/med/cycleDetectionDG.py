from collections import deque

# visiting the node in the same dfs path results in a cycle

# def dfs_traversal(i,adjList,visited,path_visited):
#     visited[i]=1
#     path_visited[i]=1

#     for neighbour in adjList[i]:
#         if visited[neighbour]==0:
#             if dfs_traversal(neighbour,adjList,visited,path_visited):
#                 return True
#         else:
#             if visited[neighbour]==path_visited[neighbour]:
#                 return True


#     path_visited[i]=0 #during backtracking


#     return False





# def detectCycle(adjList):
#     n=len(adjList)
#     visited=[0 for _ in range(n)]
#     path_visited=[0 for _ in range(n)]

#     for i in range(n):
#         if visited[i]==0:
#             if dfs_traversal(i,adjList,visited,path_visited):
#                 return True

#     return False




# using BFS
def detectCycle_using_BFS(adjList):
    n=len(adjList)
    queue=deque()
    indegree_list=[0 for _ in range(n)]

    for node,neighbours in adjList.items():
        for neighbour in neighbours:
            indegree_list[neighbour]+=1

    for i in range(n):
        if indegree_list[i]==0:
            queue.appned(i)

    ans=[]

    while queue:
        cn=queue.popleft()
        ans.append(cn)
        for neighbour in adjList[cn]:
            indegree_list[neighbour]-=1

            if indegree_list[neighbour]==0:
                queue.append(neighbour)


    if len(ans)!=n:
        print("Cycle Detected")
    else:
        print('No Cycle Detected')





if __name__=="__main__":

    adjList={
        0:[1,2],
        1:[3],
        2:[3],
        3:[]
    }

    if detectCycle(adjList):
        print("Cycle present in the directed graph")

    else:
        print("Cycle not present")
