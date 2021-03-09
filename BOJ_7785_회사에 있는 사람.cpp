#include <iostream>
#include <set>
#include <string>
using namespace std;

set<string> log_set;	// set prevents redundant data
string temp_name;
string temp_check;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> temp_name >> temp_check;

		if (temp_check == "enter") {
			log_set.insert(temp_name);
		}
		else {
			log_set.erase(temp_name);
		}
	}

	for (auto it = log_set.rbegin(); it != log_set.rend(); it++){	// from backward
		cout << *it << '\n';
	}

	return 0;
}
