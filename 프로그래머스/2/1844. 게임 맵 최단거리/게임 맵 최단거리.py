from collections import deque

dy = [0, 0, 1, -1]
dx = [1, -1, 0, 0]

def solution(maps):
    n = len(maps)
    m = len(maps[0])
    visited = [[0] * m for _ in range(n)]
    
    q = deque()
    q.append((0, 0))
    visited[0][0] = 1
    
    while q:
        y, x = q.popleft()
        
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            
            if ny < 0 or nx < 0 or ny >= n or nx >= m:
                continue
            if visited[ny][nx] > 0:
                continue
            if maps[ny][nx] == 0:
                continue
            
            q.append((ny, nx))
            visited[ny][nx] = visited[y][x] + 1
    
    return -1 if visited[n-1][m-1] == 0 else visited[n-1][m-1]