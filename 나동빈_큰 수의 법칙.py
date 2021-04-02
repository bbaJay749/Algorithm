# get N, M, K
n, m, k = map(int, input().split())
# get N numbers
data = list(map(int, input().split()))

data.sort()
first = data[n - 1]    # biggest num
second = data[n - 2]    # second biggest num

# count how many times the biggest num can be added
count = int(m / (k + 1)) * k
count += m % (k + 1)

result = 0
result += (count) * first    # sum the biggest num
result += (m - count) * second    # sum the second biggest num

print(result)


# from https://github.com/ndb796/python-for-coding-test/blob/master/3/1.py