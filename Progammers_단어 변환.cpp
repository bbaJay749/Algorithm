#include <string>
#include <vector>
using namespace std;

int answer = 999999;

void dfs(string begin, string target, vector<string> words, vector<bool>& useCheck, int cnt = 0) {
    int size_ = words.size();

    for (int i = 0; i < size_; i++) 
    {
        int count = 0;
        for (int j = 0; j < words[i].length(); j++)
            if (!useCheck[i] && begin[j] != words[i][j]) {
                count++;
            }

        if (count == 1) {
            if (target == words[i] && answer > cnt + 1) {
                answer = cnt + 1;
                return;
            }

            useCheck[i] = true;
            dfs(words[i], target, words, useCheck, cnt + 1);
            useCheck[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words)
{
    // for visit 
    vector<bool> useCheck(words.size(), false);

    dfs(begin, target, words, useCheck);

    // if there's no way
    if (answer == 999999) {
        return 0;
    }

    return answer;
}

/* revised from https://mungto.tistory.com/53 */