
#include <iostream>
using namespace std;

int F, S, G, U, D;

int main() {
	cin >> F >> S >> G >> U >> D;

	if (S == G) {
		cout << 0 << "\n";
		return 0;
	}

	for (int n = 0; n < 1000000; n++) {
		if (S == G) {
			cout << n << endl;
			return 0;
		}
		if (S + U > F&& S - D < 1) break;
		if (S < G && S + U <= F) S += U;
		else if (!(S > G && S - D < 1)) S -= D;
	}

	puts("use the stairs");

	return 0;
}
