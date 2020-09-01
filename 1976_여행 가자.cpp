#include <iostream>
#include <vector>
using namespace std;

int N, M, link;
int city, p_city;

int Find(vector<int> road, int a) { // find out the root city of city a
	a = road[a];

	while (a != road[a]) { // until the node is the root
		a = road[a]; // if not, move to the parent node
	}

	return a;
}

void Union(vector<int> &road, int a, int b) { // merge city a, b
	a = Find(road, a);
	b = Find(road, b); // get the root of city a and b

	if (a == b) {
		return;
	}

	road[a] = b; // parent node of city a is b
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	vector<int> road(N, 0);

	for (int i = 0; i < N; i++) {
		road[i] = i; // initialize the parent node as itself
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> link;
			if (link == 0) { // if i and j are not connected, do nothing
				continue;
			}
			Union(road, i, j); // if i and j are connected, Union them 
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> city; // get the next destn. city

		if (i == 0) {
			p_city = Find(road, city - 1); // initialize as the first city's root
		}
		else {
			int tmp = Find(road, city - 1); // get the root of the city

			if (tmp != p_city) { // if the root of the city and the first city's are diff.
				cout << "NO\n";
				return 0;
			}
		}
	}

	cout << "YES\n"; // means every city has the same root

	return 0;
}
