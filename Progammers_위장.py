def solution(clothes):
    answer = 1
    cloth_map = {}    # Dictionary
    
    for cloth in clothes:
        if cloth[1] in cloth_map:
            cloth_map[cloth[1]] += 1
        else:
            cloth_map[cloth[1]] = 1
    
    # only get the values of the map
    for types in cloth_map.values():
        answer *= (types + 1)
    
    return answer - 1