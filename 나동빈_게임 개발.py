# get n, m
n, m = map(int, input().split())
# get x, y, direction
x, y, direction = map(int, input().split())
# get map
gameMap = []
for i in range(n):
    gameMap.append(list(map(int, input().split())))

# declare visit list
visit = [[0] * m] * n
visit[x][y] = 1

# declare directions
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def turn_left():
    global direction
    direction -= 1
    if direction == -1:
        direction = 3

count = 1
turn_count = 0

while True:
    turn_left()
    nx = x + dx[direction]
    ny = y + dy[direction]
    
    # if there's a non-visited place in the direction and it's land
    if visit[nx][ny] == 0 and gameMap[nx][ny] == 0:
        visit[nx][ny] = 1
        x = nx
        y = ny
        count += 1
        turn_count = 0
        continue
    else:
        turn_count += 1
    # if E/W/S/N are not available
    if turn_count == 4:
        nx = x - dx[direction]
        ny = y - dy[direction]
        # go back once if possible
        if gameMap[nx][ny] == 0:
            x = nx
            y = ny
        else:
            break
        turn_count = 0

print(count)

# from https://github.com/ndb796/python-for-coding-test/blob/master/4/4.py