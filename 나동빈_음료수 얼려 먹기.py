# get N, M
n, m = map(int, input().split())

# generate map
graph = []
for i in range(n):
    graph.append(list(map(int, input())))

def dfs(x, y):
    if x <= -1 or x >= n or y <= -1 or y >= m:
        return False
    
    # if never visit
    if graph[x][y] == 0:
        # check visit
        graph[x][y] = 1
        # call all EWSN directions
        dfs(x - 1, y)
        dfs(x, y - 1)
        dfs(x + 1, y)
        dfs(x, y + 1)
        return True
    return False

result = 0
for i in range(n):
    for j in range(m):
        if dfs(i, j) == True:
            result += 1

print(result)

# from https://github.com/ndb796/python-for-coding-test/blob/master/5/10.py