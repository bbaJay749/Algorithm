#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int size_doc = priorities.size();
    deque<pair<int, int> > doc;
    
    /* push into a deque with the orders */
    for (int i = 0; i < size_doc; i++)
    {
        doc.push_back( {priorities[i], i} );
    }
    
    while (true)
    {   
        /* get the first doc */
        pair<int, int> temp_doc = doc.front();
        doc.pop_front();
        
        /* check if there's any doc with higher priority */
        bool flag = false;
        for (int i = 0; i < doc.size(); i++)
        {
            /* if yes, push the doc to the very end of the deque and check the flag*/
            if (temp_doc.first < doc[i].first) 
            {
                doc.push_back(temp_doc);
                flag = true;
                break;
            }
        }
        
        if(!flag) answer++; // if the doc has printed
        if(!flag && (temp_doc.second == location)) return answer;   // if the doc has printed and it was our target
    }
}