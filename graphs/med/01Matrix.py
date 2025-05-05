from collections import deque

def findNearest0(mat,x,y):
    if mat[x][y]==0:
        return 0
    queue=deque()
    queue.append((x,y,0))
    m=len(mat)
    n=len(mat[0])

    while queue:
        r,c,count=queue.popleft()
        for k in range(4):
            nx=r+dx[k]
            ny=c+dy[k]
            if 0<=nx<m and 0<=ny<n:
                if mat[nx][ny]==0:
                    return count+1
                else:
                    queue.append((nx,ny,count+1))




def updateMatrix(mat):

    # method 1 (calculating for each grid)
    # ans=[[0 for _ in range(mat[0]) for _ in range(mat)]]
    # for i in range(mat):
    #     for j in range(len(mat[0])):
    #         pos=findNearest0(mat,i,j)
    #         ans[i][j]=pos

    # return ans


    #method 2 (bfs from all 0s)
    m=len(mat)
    n=len(mat[0])
    queue=deque()
    ans=[[float('inf')]*n for _ in range(m)]


    for i in range(m):
        for j in range(n):
            if mat[i][j]==0:
                ans[i][j]==0
                queue.append((i,j))

    directions=[(-1,0),(0,-1),(0,1),(1,0)]
    while queue:
        r,c=queue.popleft()
        for dr,dc in directions:
            nr,nc=r+dr,c+dc
            if 0<=nr<m and 0<=nc<n:
                if ans[nr][nm]>ans[r][c]+1:
                    ans[nr][nm]=ans[r][c]+1
                    queue.append((nr,nc))

    return ans



