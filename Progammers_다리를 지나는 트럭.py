def solution(bridge_length, weight, truck_weights):
    time = 0
    bridge = [0] * bridge_length
    
    while len(bridge) != 0:
        time += 1
        bridge.pop(0)   # let go the very first element 
        
        if truck_weights:   # if truck_weights value exist 
            # if current bridge weight + new truck weight is okay
            if sum(bridge) + truck_weights[0] <= weight:
                # pop truck and push to the bridge
                bridge.append(truck_weights.pop(0))
            else:
                # if it's not ok, push 0
                bridge.append(0)
        
    return time

# revised from https://velog.io/@devjuun_s/%EB%8B%A4%EB%A6%AC%EB%A5%BC-%EC%A7%80%EB%82%98%EB%8A%94-%ED%8A%B8%EB%9F%AD-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4 */