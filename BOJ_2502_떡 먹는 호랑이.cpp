#include <iostream>
#include <vector>
using namespace std;

vector<int> fibo(31);

int main() {
	int d, k;
	cin >> d >> k;

	fibo[1] = fibo[2] = 1;

	for (int i = 3; i <= d; i++) {
		fibo[i] = fibo[i - 2] + fibo[i - 1];
	}

	// get portion of a, b 
	int a_portion = fibo[d - 2];
	int b_portion = fibo[d - 1];

	int a, b;
	for (int i = 1;; i++) {	// starting from a
		// fina a, b --> k = fibo[d-2]a + fibo[d-1]b;
		a = i;

		// if following expression isn't 0 (meets the requirement)
		if ((k - a_portion * a) % b_portion != 0) continue;
		else {
			b = (k - a_portion * a) / b_portion;
		}
		break;
	}

	cout << a << endl << b << endl;
}

/* revised from  https://jow1025.tistory.com/48 */
