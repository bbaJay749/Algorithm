n = 1260
count = 0

# check starts from the bigger one
coin_types = [500, 100, 50, 10]

for coin in coin_types:
    count += n // coin  # count how many coins fit
    n %= coin

print(count)


# from https://github.com/ndb796/python-for-coding-test/blob/master/3/1.py
