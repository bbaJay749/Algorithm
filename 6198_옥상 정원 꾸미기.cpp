#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N;
vector<int> buildings;
stack<int> por_count;
long long int result = 0;
	
int main() {
	cin >> N;

	int temp = 0;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		buildings.push_back(temp);
	}

	/* bad hair day */
	for (int i = 0; i < N; i++) {
		while (!por_count.empty() && por_count.top() <= buildings[i]) {
			por_count.pop();
		}
	
		por_count.push(buildings[i]);

		result += por_count.size() - 1;
	}

	cout << result << "\n";

	return 0;
}

/* revised from https://jaimemin.tistory.com/1363 */
