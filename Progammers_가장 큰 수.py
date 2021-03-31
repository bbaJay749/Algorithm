import functools

def comparator(a, b):
    t1 = a + b
    t2 = b + a
    
    # if t1 is bigger 1, else if t2 is bigger 2, else if they're same 0
    return (int(t1) > int(t2)) - (int(t1) < int(t2)) 

def solution(numbers):
    n = [str(x) for x in numbers]   # make every num into string
    n = sorted(n, key = functools.cmp_to_key(comparator), reverse=True)
    answer = str(int(''.join(n)))
    
    return answer

# revised from https://eda-ai-lab.tistory.com/467
