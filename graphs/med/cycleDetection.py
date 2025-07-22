from collections import deque

def detect_cycle_dfs(V,edges):
    stack=[1]
    visited=[0]*V

    while stack:
        node=stack.pop()
        for neighbor in edges[node]:
            if visited[neighbor-1]==1:
                return True
            stack.append(neighbor)
            visited[neighbor-1]=1

    return False




# using bfs
def detect_cycle_bfs(V,edges):
    queue=deque()
    queue.append(1)
    visited=[0]*V
    visited[0]=1

    while queue:
        node=queue.popleft()

        for neighbor in edges[node]:
            if visited[neighbor-1]==1:
                return True
            queue.append(neighbor)
            visited[neighbor-1]=1

    return False


if __name__=="__main__":
    V=6
    edges={
        1:[2,3],
        2:[1,6],
        3:[1,4],
        4:[3,5],
        5:[4,6],
        6:[2,5],
    }

    if(detect_cycle_bfs(V,edges)):
        print("Cycle present in the graph")
    else:
        print("Cycle not present")
