#I am able to color using 2 colors such that no two adjacent nodes have the same color

# in this problem given a graph we have to show whether that graph is bipartite or not

def traverse(indx,color_track,adj_list,0):
    if color_track[indx]==-1:
        color_track[indx]=0
        for neighbour in adj_list:  
            if color_track[neigbour]
            




def check_bipartite(adj_list):

    V=len(adj_list)
    color_track=[-1 for _ in range(V)]

    if traverse(0,color_track,adj_list,0):
        return True

    return False
