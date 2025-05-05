def floodFill(image, sr, sc, color):
    
    
    directions=[(-1,0),(0,-1),(1,0),(0,1)]
    queue=deque()
    inital_color=image[sr][sc]

    if initial_color==color:
        return image

    image[sr][sc]=color
    queue.append((sr,sc))

    m,n=len(grid),len(grid[0])

    while queue:
        r,c=queue.popleft()
        for dr,dc in directions:
            nr,nc=r+dr,c+dc
            if 0<=nr<m and 0<=nc<n and image[nr][nc]==initial_color:
                image[nr][nc]=color
                queue.append(nr,nc)
        
    return image

