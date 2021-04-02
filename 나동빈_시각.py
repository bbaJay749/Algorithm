# get N
N = input()

count = 0

for i in range(N + 1):
    for j in range(60):
        for k in range(60):
            if '3' in str(i) + str(j) + str(k):
                count += 1


# from https://github.com/ndb796/python-for-coding-test/blob/master/4/2.py
