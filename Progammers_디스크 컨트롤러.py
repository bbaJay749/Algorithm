import heapq

def solution(jobs):
    count, last, answer = 0, -1, 0
    heap = []
    
    # sort in Ascending order (requested time) 
    jobs.sort()
    time = jobs[0][0]
    
    while count < len(jobs):
        for requested_time, time_consume in jobs:
            if last < requested_time <= time:
                # min heap by time_consume
                heapq.heappush(heap, (time_consume, requested_time))
                
        # if there are tasks can be done
        if len(heap) > 0:
            count += 1
            last = time
            term, start = heapq.heappop(heap)
            time += term
            answer += (time - start)   
        # else time++
        else:
            time += 1
            
    return answer//len(jobs)