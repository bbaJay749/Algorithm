#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    string str;
    int len, N;

    list<char> editList;

    cin >> str;
    cin >> N;

    len = str.length();;

    for (int i = 0; i < len; i++) {
        editList.push_back(str[i]);
    }

    auto cursor = editList.end();

    for (int i = 0; i < N; i++) {
        char order;
        cin >> order;

        switch (order) {
        case 'L':
            if (cursor != editList.begin()) {
                cursor--;
            }
            break;

        case 'D':
            if (cursor != editList.end()) {
                cursor++;
            }
            break;

        case 'B':
            if (cursor != editList.begin()) {
                cursor--;
                cursor = editList.erase(cursor);  // Cursor becomes the right element of the erased element
            }
            break;

        case 'P':
            char inchar;
            cin >> inchar;
            editList.insert(cursor, inchar);
            break;
        }
    }

    for (auto iter = editList.begin(); iter != editList.end(); iter++) {
        cout << *iter;
    }

    cout << endl;
    return 0;
}

/* revised from https://tdm1223.tistory.com/62 */
