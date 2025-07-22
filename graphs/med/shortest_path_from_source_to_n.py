from typing import List
import heapq

def shortestPath(self,n:int, m:int, edges:List[List[int]] )->List[int]:


    dist=[float('inf') for i in range(n+1)]
    parent=[]
    for i in range(n+1):
        parent.append(i)

    adjList=[[] for i in range(n+1)]

    for edge in edges:
        for n1,n2,w in edge:
            adjList[n1].append((n2,w))


    queue=[]
    heapq.heapify(queue)

    heapq.heappush(queue, (0,1))  #storing as (dist,node)


    while queue:
        current_dist,current_node = heapq.heappop(queue)
        for node,weight in adjList[current_node]:
            if dist[node]>current_dist+weight:
                dist[node]=current_dist+weight
                heapq.heappush(queue,(dist[node],node))
                parent[node]=current_node


    shortest_path=[]
    node=n
    while(parent[node]!=node):
        shortest_path.add(node)
        node=parent[node]

    shortest_path.append(1)

    return shortest_path
