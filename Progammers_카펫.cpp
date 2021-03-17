#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int ver = 0;
    int hor = yellow;
    
    /* try every retangular can be made with yellow */
    while(true)
    {   
        ver++;
        if((yellow % ver) == 0) // if hor, ver are resonable
        {
            hor = yellow / ver;
            cout << hor << " " << ver;
        }
        else continue;
        
        /* compare with the num of brown */ 
        if((ver * 2) + (hor * 2) + 4 == brown) 
        {
            answer = {hor + 2, ver + 2};    // brwon is bigger than yellow
            break;
        }
    }
    
    return answer;
}