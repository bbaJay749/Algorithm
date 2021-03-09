#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

struct Node {
	vector<int> n;	// vector which has index of next nodes
	int time = 0;	// time spent to reach this node
};

int main() {
	int T = 0;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N = 0, K = 0;
		cin >> N >> K;

		vector<int> D(N, 0);
		for (int i = 0; i < N; i++) {
			cin >> D[i];
		}

		vector<Node> node(N);	// vector of nodes
		vector<int> inDegree(N, 0);	// to count how many indegrees does each node have

		for (int a = 0; a < K; a++) {
			int x = 0, y = 0;
			cin >> x >> y;
			node[x - 1].n.push_back(y - 1);	// get which node goes to which node
			inDegree[y - 1]++; // increase indegree
		}
		int W = 0;
		cin >> W;	// the num of the node we want to know how long does it take to build

		queue<int> q; // for bfs
		for (int i = 0; i < N; i++) {
			// if the node has no indegree
			if (inDegree[i] == 0) q.push(i);
		}

		while (!q.empty()) {
			int b = q.front();
			q.pop();

			if (b == W - 1) {	// if we built W
				break;
			}

			int len = node[b].n.size();
			for (int i = 0; i < len; i++) { // check nodes after current node
				inDegree[node[b].n[i]]--; // indegree-- cuz current node has been popped
				if (inDegree[node[b].n[i]] == 0) { // if current node has no more indegree
					q.push(node[b].n[i]); // push into the queue
				}
				/* if saved times take shorter than current caculated one, change it into longer one */
				if (node[node[b].n[i]].time < node[b].time + D[b]) {
					node[node[b].n[i]].time = node[b].time + D[b];
				}
			}
		}

		/* add final building's time */
		cout << node[W - 1].time + D[W - 1] << '\n'; 
	}

	return 0;
}
