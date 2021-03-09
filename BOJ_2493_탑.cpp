#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N, h;
stack<pair<int, int> > stock_span;
vector<int> answer;

int main() 
{
	cin >> N;

	/*	1. get the index and heights 
		2. pop til the stack is empty or the top > h
			- if stack is empty, there's no tower possible
			- if stack's top > h, that's the tower fits
		3. push {index, h} into the stack */

	for (int i = 0; i < N; i++) {
		cin >> h;

		while (!stock_span.empty() && stock_span.top().second < h) {
			stock_span.pop();
		}

		if (stock_span.empty()) {
			answer.push_back(0);
		}
		else {
			answer.push_back(stock_span.top().first + 1);
		}

		stock_span.push({ i, h });
	}

	for (int i = 0; i < N; i++) {
		cout << answer[i] << " ";
	}

	return 0;
}
