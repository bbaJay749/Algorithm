#include <iostream>
#include <vector>
using namespace std;

long long Pinary(int num){
	vector<long long> pinary(90, 0);		// why long long ??
	pinary[0] = 0;
	pinary[1] = 1; 

	for (int i = 2; i < num + 1; i++) {

		pinary[i] = pinary[i - 1] + pinary[i - 2];

	}

	return pinary[num];
}

int main() {
	int N;
	cin >> N;

	cout << Pinary(N) << endl;

	return 0;
}

/* Dumb way
int main() {
    int N = 0, totalnum = 0;
    cin >> N;
    totalnum = pow(2, N);

    vector<vector<bool>> Pinary(pow(2, N), vector<bool> (N, 0));

    for (int i = 1; i < pow(2, N); i++) {
        bool flag = 0;
        Pinary[i] = Pinary[i - 1];
        putnum(Pinary, i, 0, flag);
    }

    for (int i = 0; i < pow(2, N); i++) {
        for (int k = 0; k < N; k++) {
            cout << Pinary[i][k];
        }
        cout << endl;
    }

    for (int i = 0; i < pow(2, N); i++) {
        bool flag = 0;
        for (int k = 1; k < N; k++) {
            if (flag == 0) {
                if (Pinary[i][0] == 0) {
                    totalnum--;
                    flag = 1;
                }
                else if (Pinary[i][k] == 1 && Pinary[i][k - 1] == 1) {
                    totalnum--;
                    flag = 1;
                }
            }
            /*if (flag == 1) {
                if (Pinary[i][k] == 1 && Pinary[i][k - 1] == 1) {
                    totalnum++;
                    break;
                }
            }*/
        }
    }

    cout << totalnum << endl;

    return 0;
}

void putnum(vector<vector<bool>> &Pinary, int i, int k, int flag) {
    if (flag == 1) return;

    if (Pinary[i][k] == 0) {
        Pinary[i][k] = 1;
        flag = 1;
        return;
    }
    else {
        Pinary[i][k] = 0;
        putnum(Pinary, i, k + 1, flag);
    }
}
*/

