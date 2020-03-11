#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int size;
    int result = 0;
    cin >> size;

    int* A = new int[size]();
    int* B = new int[size]();

    for (int i = 0; i < size; i++) cin >> A[i];
    for (int i = 0; i < size; i++) cin >> B[i];
    sort(A, A + size);
    sort(B, B + size, greater<int>());

    for (int i = 0; i < size; i++) {
        result += (A[i] * B[i]);
    }
    cout << result << endl;

    return 0;
}

/* dang stupid & wrong way */
/*
int main() {
    int size;
    cin >> size;

    int* A = new int[size]();
    int* B = new int[size]();
    int* B_copy = new int[size]();
    int* B_index = new int[size]();
    int* A_revised = new int[size]();
    int result = 0;

    for (int i = 0; i < size; i++) cin >> A[i];
    for (int i = 0; i < size; i++) cin >> B[i];
    copy(B, B+size, B_copy);
    sort(A, A + size);

    for (int j = 0; j < size; j++) {
        int max = B[0];
        int index = 0;

        for (int i = 0; i < size; i++) {
            if (B[i] > max) {
                max = B[i];
                index = i;
            }
        }

        B[index] = 0;
        B_index[j] = index;
    }

    for (int i = 0; i < size; i++) {
        A_revised[B_index[i]] = A[i];
    }

    for (int i = 0; i < size; i++) cout << A_revised[i];
    cout  << endl;
    for (int i = 0; i < size; i++) cout << B_copy[i];
    cout << endl;

    for (int i = 0; i < size; i++) {
        result += (A_revised[i] * B_copy[i]);
    }
    cout << result << endl;

    return 0;
}
*/
