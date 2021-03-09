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
		// arrive
		if (S == G) {
			cout << n << endl;
			return 0;
		}
		// current loc + up && current loc - down is not available
		if (S + U > F && S - D < 1) break;
		// if current loc + up is available
		if (S < G && S + U <= F) S += U;
		// if current loc - down is available
		else if (!(S > G && S - D < 1)) S -= D;
	}

	puts("use the stairs");

	return 0;
}
