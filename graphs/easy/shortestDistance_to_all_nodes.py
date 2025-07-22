from collections import deque
import heapq

# def ShortestDistInUG_with_unit_weight(adjList,src):

#     queue=deque()

#     dist=[float('inf') for _ in range(len(adjList))]

#     queue.append(src)

#     while queue:
#         current_node=queue.popleft()
#         for neighbour in adjList[current_node]:
#             if dist[neighbour]>dist[current_node]+1:
#                 dist[neighbour]=dist[current_node]+1
#                 queue.append(neighbour)

#     return dist



# for Undirected graph with non zero weights
def ShortestDistInUG_with_non_zero_weight(adjList,src):

    # using bfs
    queue=deque()
    queue.append((src,0))

    dist=[float('inf') for _ in range(len(adjList))]
    dist[src]=0

    while queue:
        current_node,current_dist=queue.popleft()
        for neighbour,neighbour_dist in adjList[current_node]:
            if dist[neighbour]>dist[current_node]+neighbour_dist:
                dist[neighbour]=dist[current_node]+neighbour_dist
                queue.append((neighbour,dist[neighbour]))




    # using Dijkstra

    # if edges given as argument
    # adjList=[[] for i in range(V)]

    # for n1,n2,weight in edges:
    #     adjList[n1].append((n2,weight))


    dist=[float('inf') for _ in range(V)]
    dist[src]=0
    queue=[]
    queue.append((0,src))
    heapq.heapify(queue)

    while queue:
        current_weight,current_node=heapq.heappop(queue)
        for neighbour,neighbour_weight in adjList[current_node]:
            if dist[neighbour]>current_weight+neighbour_weight:
                dist[neighbour]=current_weight+neighbour_weight
                queue.append((dist[neighbour],neighbour))



    return dist


# sample test_case
# adjList = {
#     0: [(1, 10), (2, 1)],
#     1: [(0, 10), (3, 1)],
#     2: [(0, 1), (3, 100)],
#     3: [(1, 1), (2, 100)]
# }

# print(ShortestDistInUG_with_non_zero_weight(adjList,0))




# for Directed Acyclic Graph with non zero weight
def getTopoSort(V,adjList):
        stack=[]
        indegree_arr=[0 for _ in range(V)]

        for i in range(V):
            for neighbour,weight in adjList[i]:
                indegree_arr[neighbour]+=1


        topoSort=[]
        queue=deque()

        for i in range(V):
            if indegree_arr[i]==0:
                queue.append(i)

        while queue:
            current_node=queue.popleft()
            topoSort.append(current_node)
            for neighbour,weight in adjList[current_node]:
                indegree_arr[neighbour]-=1
                if indegree_arr[neighbour]==0:
                    queue.append(neighbour)

        return topoSort





def ShortestDistInDAG(V,edges,src):

    # creating adjList from edges
    adjList=[[] for _ in range(V)]
    for edge in edges:
        n1,n2,w=edge
        adjList[n1].append((n2,w))



    dist=[float('inf') for _ in range(V)]
    dist[src]=0



    # using bfs
    # queue=deque()
    # queue.append((src,0))


    # while queue:
    #     current_node,current_dist=queue.popleft()
    #     for neighbour,neighbour_weight in adjList[current_node]:
    #         if dist[neighbour]>dist[current_node]+neighbour_weight:
    #             dist[neighbour]=dist[current_node]+neighbour_weight  #update distance when it is shorter then the distance stored in the array
    #             queue.append((neighbour,dist[neighbour]))



    # using topoSort
    stack=getTopoSort(V,adjList)
    dist[0]=0

    for node in stack:
        for neighbour,weight in adjList[node]:
            if dist[neighbour]>dist[node]+weight:
                dist[neighbour]=dist[node]+weight


    for i in range(V):
        if dist[i] == float('inf'):
            dist[i]=-1


    return dist
