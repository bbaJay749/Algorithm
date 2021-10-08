from collections import deque

# get N, M
n, m = map(int, input().split())

# generate map
graph = []
for i in range(n):
    graph.append(list(map(int, input())))

# directions
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(x, y):
    queue = deque()
    queue.append((x, y))
    
    # until queue is empty
    while queue:
        x, y = queue.popleft()
        
        # check all directions
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            # out of map
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            # if it's wall
            if graph[nx][ny] == 0:
                continue
            # check only it's the 1st visit
            if graph[nx][ny] == 1:
                graph[nx][ny] = graph[x][y] + 1
                queue.append((nx, ny))
                
    # get the shortest way
    return graph[n - 1][m - 1]

print(bfs(0, 0))

# from https://github.com/ndb796/python-for-coding-test/blob/master/5/11.py