# get N, M
N, M = map(int, input().split())
result = []

# get each row and append the min value to 'result'
for _ in range(N):
    row = list(map(int, input().split()))
    result.append(min(row))

# get max value of result
print(max(result))


# from https://github.com/ndb796/python-for-coding-test/blob/master/3/3.py