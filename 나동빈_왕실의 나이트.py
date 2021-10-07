# get location of knight
input_data = input()
row, col = int(input_data[1]), int(ord(input_data[0])) - int(ord('a')) + 1

steps = {(-1, -2), (-1, 2), (1, -2), (1, 2), (-2, -1), (-2, 1), (2, -1), (2, 1)}

result = 0

for step in steps:
    next_row = row + step[0]
    next_col = col + step[1]
    
    if (next_row >= 1) and (next_row <= 8) and (next_col >= 1) and (next_col <= 8):
        result += 1
        
print(result)

# from https://github.com/ndb796/python-for-coding-test/blob/master/4/3.py