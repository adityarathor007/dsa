from collections import deque

def dfs_traversal(x,adjList,visited,stack):
    visited[x]=1
    for neighbour in adjList[x]:
        if visited[neighbour]==0:
            dfs_traversal(neighbour,adjList,visited,stack)

    stack.append(x)


def getTopoSort(adjList):
    n=len(adjList)
    stack=[]
    visited=[0 for _ in range(n)]

    for i in range(n):
        if visited[i]==0:
            dfs_traversal(i,adjList,visited,stack)


    # print(stack)
    ans=stack[::-1]

    return ans



# using kahn algorithm (BFS)
def getTopoSort_BFS(adjList):

    queue=deque()
    n=len(adjList)

    indegree_arr=[0 for _ in range(n)]

    for node,neighbours in adjList.items():
        for neighbour in neighbours:
            indegree_arr[neighbour]+=1


    for i in range(n):
        if indegree_arr[i]==0:
            queue.append(i)


    ans=[]
    while queue:
        cn=queue.popleft()
        ans.append(cn)
        for neighbour in adjList[cn]:
            indegree_arr[neighbour]-=1
        if indegree_arr[neighbour]==0:
            queue.append(neighbour)

    return ans



if __name__=="__main__":
    adjList={
        0:[1,4],
        1:[2],
        2:[3],
        3:[],
        4:[3]
    }
    getTopoSort_BFS(adjList)
