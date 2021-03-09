#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int size_v, size_h;
int num_drawings;
int size_drawing, L_size_drawing;
bool flag, dot;

void dfs(bool drawings[500][500], bool checker[500][500], int i, int j) {
    if (!checker[i][j]) {
        checker[i][j] = true;
        if (drawings[i][j]) {
            if (!flag) {
                flag = true; 
                num_drawings++;
            }
            L_size_drawing++;

            if (0 < i) dfs(drawings, checker, i - 1, j);
            if (i < size_v - 1) dfs(drawings, checker, i + 1, j);
            if (0 < j) dfs(drawings, checker, i, j - 1);
            if (j < size_h - 1) dfs(drawings, checker, i, j + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    bool drawings[500][500] = { 0 };
    bool checker[500][500] = { 0 };
    cin >> size_v >> size_h;

    for (int i = 0; i < size_v; i++) {
        for (int j = 0; j < size_h; j++) {
            cin >> dot;
            drawings[i][j] = dot;
        }
    }

    for (int i = 0; i < size_v; i++) {
        for (int j = 0; j < size_h; j++) {
            L_size_drawing = 0;
            flag = 0;
            dfs(drawings, checker, i, j);
            if (L_size_drawing > size_drawing) size_drawing = L_size_drawing;
        }
    }

    cout << num_drawings << endl << size_drawing << endl;

    return 0;
}
