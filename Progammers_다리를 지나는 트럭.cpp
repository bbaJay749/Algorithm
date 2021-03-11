#include <string>
#include <vector>
#include <queue>
using namespace std;
 
int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    queue<int> bridge;
    int time = 0;
    int sum_weight = 0;
    int truckIdx = 0;
    
    while(1)
    {    
        time++;
        
        // if the queue size == length of bridge, it means trucks arrive
        if(bridge.size() == bridge_length)
        {
            sum_weight -= bridge.front();
            bridge.pop();
        }
        
        // if sum_weight + truckweights is okay
        if(sum_weight + truck_weights[truckIdx] <= weight)
        {
            // if last truck
            if(truckIdx == truck_weights.size() - 1)
            {
                // add time for the last truck
                time += bridge_length;
                break;
            }
            
            // let go truck
            bridge.push(truck_weights[truckIdx]);
            sum_weight += truck_weights[truckIdx];
            truckIdx++;
        }
        // if sum_weight + truckweights is NOT okay, let go 0
        else
        {
            bridge.push(0);
        }    
    }
    
    return time;
}

/* revised from https://rile1036.tistory.com/12 */