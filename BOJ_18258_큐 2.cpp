#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> por_queue(2000000);
string order_queue;
int N, number, front_queue, rear_queue, size_queue;

void get_size() {
	cout << size_queue << "\n";
}

void push(int x) {
	por_queue[rear_queue] = x;
	size_queue += 1;
	rear_queue += 1;
}

void get_empty() {
	if (size_queue == 0) cout << 1 << "\n";
	else cout << 0 << "\n";
}

void front() {
	if (size_queue == 0) cout << -1 << "\n";
	else cout << por_queue[front_queue] << "\n";
}

void back() {
	if (size_queue == 0) cout << -1 << "\n";
	else cout << por_queue[rear_queue - 1] << "\n";
}

void pop() {
	if (size_queue == 0) cout << -1 << "\n";
	else {
		cout << por_queue[front_queue] << "\n";
		por_queue[front_queue] = 0;
		front_queue += 1;
		size_queue -= 1;
	}
}

int main() {
	/* without these 2 lines, meets time limit fail */
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> order_queue;

		if (order_queue == "push") {
			cin >> number;
			push(number);
		}
		else if (order_queue == "front") front();
		else if (order_queue == "back") back();
		else if (order_queue == "size") get_size();
		else if (order_queue == "empty") get_empty();
		else if (order_queue == "pop") pop();
	}

	return 0;
}
