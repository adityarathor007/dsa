def dfs_traversal(x,y,grid,visited):
    visited[x][y]=1
    m=len(grid)
    n=len(grid[0])

    directions=[(-1,0),(-1,-1),(0,-1),(1,-1),(0,1),(1,1),(0,1),(-1,1)]

    for dx,dy in directions:
        nx=x+dx
        ny=y+dy
        if 0<=nx<m and 0<=ny<n and visited[nx][ny]==0 and grid[nx][ny]==1:
            dfs_traversal(nx,ny,grid,visited)



def findIslands(grid):
    m=len(grid)
    n=len(grid[0])
    visited=[[0 for _ in range(n)] for _ in range(m)]

    count=0

    for i in range(m):
        for j in range(n):
            if visited[i][j]==0 and grid[i][j]==1:
                count+=1
                dfs_traversal(i,j,grid,visited)

    return count

if __name__=="__main__":
    # grid=[[0,1,1,0,1,0,0],[0,0,1,1,0,1,0]]
    grid=[[0,1,1,0],[0,1,1,0],[0,0,1,0],[0,0,0,0],[1,1,0,1]]
    print(findIslands(grid))