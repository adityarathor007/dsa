from typing import List
from collections import deque

def shortestPath(n:int, m:int, edges:List[List[int]] )->List[int]:
        # code here
        # creating adjList
        adjList=[[] for _ in range(n+1)]

        for src,target,weight in edges:
            adjList[src].append([target,weight])


        # the bfs algorithm
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



        return dist


n = 5
m= 6
edges = [[0, 1, 2], [1, 4, 5], [1, 2, 4], [0, 3, 1], [3, 2, 3], [2, 4, 1]]
print(shortestPath(n,m,edges))
