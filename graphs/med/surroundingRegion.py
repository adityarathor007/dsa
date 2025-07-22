from collections import deque

def find_connected_neighbors(self,x,y,board,visited):
        m=len(board)
        n=len(board[0])
        queue=deque()
        queue.append((x,y))

        directions=((-1,0),(0,-1),(1,0),(0,1))


        while queue:
            cx,cy=queue.popleft()
            visited[cx][cy]=1

            for dx,dy in directions:
                nx=cx+dx
                ny=cy+dy
                if 0<=nx<m and 0<=ny<n and board[nx][ny]=="O" and visited[nx][ny]==0:
                    queue.append((nx,ny))




def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        m=len(board)
        n=len(board[0])

        visited=[[0 for _ in range(n)] for _ in range(m)]



        for i in range(m):
            if board[i][0]=="O" and visited[i][0]==0:
                self.find_connected_neighbors(i,0,board,visited)

            if board[i][n-1]=="O" and visited[i][n-1]==0:
                self.find_connected_neighbors(i,n-1,board,visited)

        for j in range(n):
            if board[0][j]=="O" and visited[0][j]==0:
                self.find_connected_neighbors(0,j,board,visited)
            if board[m-1][j]=="O" and visited[m-1][j]==0:
                self.find_connected_neighbors(m-1,j,board,visited)

        for i in range(m):
            for j in range(n):
                if board[i][j]=="O" and visited[i][j]==0:
                    board[i][j]="X"
