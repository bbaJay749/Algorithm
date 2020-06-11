#include <iostream>
#include <vector>
using namespace std;

int T, N;
vector<int> students;

void cal() {
	int answer = 0;
	int group_num = 1;
	vector<bool> visited(N, false);
	vector<int> group(N, 0);
	vector<int> visited_node;	// temporal cycling students

	for (int i = 0; i < N; i++) {

		// if the student already has a group num, skip 
		if (group[i] || visited[i] == true) continue;

		visited_node.clear();
		visited[i] = true;
		visited_node.push_back(i);

		int cur_node = students[i];
		// scan only !visited node && had no group(=0) 
		while (!visited[cur_node] && group[cur_node] == 0) {
			visited[cur_node] = true;
			visited_node.push_back(cur_node);
			cur_node = students[cur_node];
		}

		/*	if origin and destin. same after scan cycle, find where does the cycle starts.
			if it's not the node which starts cycle, put -1 to mark it's not groupable */
		int visited_size = visited_node.size();
		for (int j = 0; j < visited_size; j++) {
			if (visited_node[j] != cur_node) {
				group[visited_node[j]] = -1;
			}
			else {
				for (int k = j; k < visited_size; k++) {
					group[visited_node[j]] = group_num;
				}
				group_num++;
				break;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (group[i] < 0) answer++;
	}

	cout << answer << "\n";

	return;
}

int main() {
	ios::sync_with_stdio(false);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		students = vector<int>(N, 0);

		for (int j = 0; j < N; j++) {
			cin >> students[j];
			students[j] -= 1;
		}
		cal();
	}

	return 0;
}
