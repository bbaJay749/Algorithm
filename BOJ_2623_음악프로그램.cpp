#include <iostream>
#include <vector>
using namespace std;

struct Singer {
	int indegree = 0;
	vector<int> next_singer;
}; // indegree : num of the singers should be pre-located, next_singer : num of the singers can be located right after current singer

int main() {
	int N, M;
	cin >> N >> M;

	vector<Singer> singer(N);
	for (int m = 0; m < M; m++) {
		int num;
		cin >> num;

		int prev;
		cin >> prev;
		--prev;
		for (int n = 1; n < num; n++) {
			int tmp;
			cin >> tmp;
			tmp--;
			singer[tmp].indegree++;
			singer[prev].next_singer.push_back(tmp);
			prev = tmp;
		}
	}

	vector<int> result;
	while (true) { // Topological Sort
		int idx = -1;
		for (int i = 0; i < N; i++) {
			if (singer[i].indegree == 0) { // if indegree is 0, they are able to be located here
				singer[i].indegree--; // indegree-- cuz they located here (kinda visit)
				idx = i;
				result.push_back(i + 1);
				break;
			}
		}

		if (idx == -1) { // if no more singers are able to be located
			break;
		}

		for (int i = 0; i < singer[idx].next_singer.size(); i++) {
			int tmp = singer[idx].next_singer[i];
			singer[tmp].indegree--; // the singers available at the right next time, indegree--;
		}
	}

	if (result.size() != N) { // it no one's available
		cout << 0;
	}
	else {
		for (int i = 0; i < N; i++) {
			cout << result[i] << '\n';
		}
	}

	return 0;
}
