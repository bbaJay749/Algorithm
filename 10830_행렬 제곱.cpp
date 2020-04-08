#include <iostream>
using namespace std;

long long a[6][6], ans[6][6], n, b;
void cal(long long A[6][6], long long B[6][6]);

int main() {
	cin >> n >> b;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
		ans[i][i] = 1;
	}

	while (b > 0) {
		if (b % 2 == 1) {
			cal(ans, a);
		}
		cal(a, a);
		b /= 2;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;;
	}
}

void cal(long long A[6][6], long long B[6][6]){
	long long C[6][6];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			C[i][j] = 0;
			for (int k = 1; k <= n; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
			C[i][j] %= 1000;
		}
	}
		
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			A[i][j] = C[i][j];
		}
	}
}
