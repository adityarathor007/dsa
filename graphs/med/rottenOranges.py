from collections import deque

def find_rotten_oranges(grid):
    m,n=len(grid),len(grid[0])
    queue=deque()
    fresh=0

    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j]==2:
                queue.append((i,j,0))  #to keep track of the starting point
            elif grid[i][j]==1:
                fresh+=1    #to keep track of the number of fresh oranges

    directions=[(-1,0),(0,-1),(1,0),(0,1)]
    minutes=0

    while queue:
        r,c,minutes=queue.popleft()
        for dr,dc in directions:
            nr,nc=r+dr,c+dc
            if 0<=nr<m and 0<=nc<n and grid[nr][nc]==1:
                grid[nr][nc]=2 #so that other cells dont count it as converting to rotten
                fresh-=1
                queue.append((nr,nc,minutes+1))


    return minutes if fresh==0 else -1


if __name__=='__main__':
    grid=[[2,1,1],[1,1,0],[0,1,1]]

    print(find_rotten_oranges(grid))

