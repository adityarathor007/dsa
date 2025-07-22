class Solution(object):
    def dfs_traversal(self,x,graph,color,color_track):
        color_track[x]=color
        for neighbour in graph[x]:
            if color_track[neighbour]==-1:
                if color==0:
                    if self.dfs_traversal(neighbour,graph,1,color_track) == False:
                        return False
                else:
                    if self.dfs_traversal(neighbour,graph,0,color_track) == False:
                        return False
            else:
                if color_track[neighbour]==color:
                    return False


        return True

    def isBipartite(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: bool
        """

        n=len(graph)
        color_track=[-1 for _ in range(n)]
        for i in range(n):
            if color_track[i]==-1:
                if self.dfs_traversal(i,graph,0,color_track)==False:
                    return False

        return True


