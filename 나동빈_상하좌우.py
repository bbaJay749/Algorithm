
# get N, Plans
N = int(input())
Plans = input().split()
x, y = 1, 1

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]
move_types = ['L', 'R', 'U', 'D']

# check each plan
for plan in Plans:
    for i in range(len(move_types)):
        # get next position
        if plan == move_types[i]:
            nx = x + dx[i]
            ny = y + dy[i]
    # if nx, ny are not appropriate
    if nx < 1 or ny < 1 or nx > N or ny > N:
        continue
    # assign next position
    x, y = nx, ny

print(x, y)


# from https://github.com/ndb796/python-for-coding-test/blob/master/4/1.py
