#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main(void){
    int test_case;
    cin >> test_case;

    for (int t = 0; t < test_case; t++) {
        string s;
        cin >> s;

        stack<char> result; // 결과
        stack<char> temp; // 화살표 입력 시 필요

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '<') {
                if (!result.empty()) {
                    temp.push(result.top());
                    result.pop();
                }
            }
            else if (s[i] == '>') {
                if (!temp.empty()) {
                    result.push(temp.top());
                    temp.pop();
                }
            }
            else if (s[i] == '-') {
                if (!result.empty()) result.pop();
            }
            else {
                result.push(s[i]);
            }
        }

        while (!temp.empty()) {
            result.push(temp.top());
            temp.pop();
        }

        string answer;
        while (!result.empty()) {
            answer += result.top();
            result.pop();
        }

        //LIFO이기 때문에
        reverse(answer.begin(), answer.end());
        cout << answer << "\n";
    }
    return 0;
}

/* revised from https://jaimemin.tistory.com/824 */
