#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int size_v, size_h;
int num_drawings;
int size_drawing, L_size_drawing;
bool flag, dot;

void getdrawing(bool drawings[501][501], bool checker[501][501], int i, int j) {
    if (!checker[i][j]) {
        checker[i][j] = true;
        if (drawings[i][j]) {
            if (!flag) {
                flag = true; num_drawings++;
            }
            L_size_drawing++;
            if (0 < i) getdrawing(drawings, checker, i - 1, j);
            if (i < size_v) getdrawing(drawings, checker, i + 1, j);
            if (0 < j) getdrawing(drawings, checker, i, j - 1);
            if (j < size_h) getdrawing(drawings, checker, i, j + 1);
        }
    }
    else;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    bool drawings[501][501] = { 0 };
    bool checker[501][501] = { 0 };
    cin >> size_v >> size_h;

    for (int i = 0; i < size_v; i++) {
        for (int j = 0; j < size_h; j++) {
            cin >> dot;
            drawings[i][j] = dot;
        }
    }

    for (int i = 0; i < size_v; i++) {
        for (int j = 0; j < size_h; j++) {
            L_size_drawing = 0; flag = 0;
            getdrawing(drawings, checker, i, j);
            if (L_size_drawing > size_drawing) size_drawing = L_size_drawing;
        }
    }

    cout << num_drawings << endl << size_drawing << endl;

    return 0;
}
