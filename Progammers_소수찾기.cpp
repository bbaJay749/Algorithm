#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

#define MAX_V 9999999
#define LONG unsigned long long

/* find prime num */
void prime(vector<bool>& isPrime, const int size) {
	for (LONG ii = 2; ii <= size; ii++) {
		if (isPrime[ii] == false) {
			for (LONG jj = ii * ii; jj <= size; jj += ii) { isPrime[jj] = true; }
		}
	}
}

/* Create Number */
void createNumber(int index, int& maxVal, const int length, string bucket, const string message, vector<bool>& visited, unordered_set<int>& answer) {

	// Case Index Excess
	if (index > length) { return; }

	const int value = atoi(bucket.c_str());
	maxVal = max(maxVal, value);
	answer.insert(value);

	for (int ii = 0; ii < length; ii++) {
		if (visited[ii] == false) {
			visited[ii] = true;
			bucket.push_back(message[ii]);
			createNumber(index + 1, maxVal, length, bucket, message, visited, answer);
			bucket.pop_back();
			visited[ii] = false;
		}
	}
}

int solution(string numbers) {

	int answer = 0;
	int maxVal = 0;

	unordered_set<int> bucket;
    vector<bool> visited(numbers.size(), false);
	createNumber(0, maxVal, numbers.size(), string(), numbers, visited, bucket);

  /* get Prime num from 0 ~ maxVal */
	vector<bool> isPrime(maxVal + 1, false);
	prime(isPrime, maxVal + 1);

	for (auto begin = bucket.begin(); begin != bucket.end(); begin++) {
		if (isPrime[*begin] == false && *begin >= 2) { answer++; }
	}

	return answer;
}

/* revised from https://dev-dream-world.tistory.com/16 */