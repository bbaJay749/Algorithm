# get N, K
n, k = map(int, input().split())
result = 0

# if N >= K, keep dividing 
while n >= k:

    # keep -1 until N % K becomes 0
    while n % k != 0:
        n -= 1
        result += 1

    # devide by K
    n //= k
    result += 1

# keep -1 until N becomes 1
result += (n - 1)

print(result)


# from https://github.com/ndb796/python-for-coding-test/blob/master/3/5.py