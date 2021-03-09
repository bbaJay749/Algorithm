#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool analysis() {
    stack<bool> check;
    string PS;
    cin >> PS;

    int len = PS.length();

    for (int i = 0; i < len; i++) {
        if (PS[i] == ')') {
            if (check.empty() == true) return false;
            else check.pop();
        }
        else if (PS[i] == '(') {
            check.push(1);
        }
    }

    if (check.empty() == true) return true;
    else if (check.empty() == false) return false;
}

int main() {
    int N = 0;
    cin >> N;

    for (int t = 0; t < N; t++) {
        if (analysis()) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
