#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string arrange;
    stack<bool> count;
    int pieces = 0;

    cin >> arrange;
    
    for (int i = 0; i < arrange.length(); i++) {
        if (arrange[i] == '(') {    // count the sticks
            count.push(1);
        }
        else if (arrange[i] == ')') {     
            count.pop();

            if (arrange[i - 1] == '(') {    // if it's a lazer(), add sticknum
                pieces += count.size();
            }
            else if (arrange[i - 1] == ')') {   // if it's just the end of the stick, add 1
                pieces += 1;
            }
        }
    }

    cout << pieces << endl;

    return 0;
}
