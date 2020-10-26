#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, temp;
long long int sum = 0;

int main() 
{
	cin >> N;
	vector<int> num;

	int neg = 0;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		num.push_back(temp);

		if (num[i] <= 0) {	// count negative num
			neg++;
		}
	}

	sort(num.begin(), num.end());

	if (neg % 2 != 0) { // if the num of negative num is odd
		sum += num[neg - 1]; // add the mininum num 
	}
	for (int i = 0; i < neg - 1; i++) { // other negative nums should be added after multiplied in increasing order
		sum += num[i] * num[i + 1];
		i++;
	}

	while (num[neg] == 1) {
		sum += 1; // 1 must go as add not multiply
		neg++;
	}
	if ((N - neg) % 2 != 0) { // if the number of pos num except 1 is odd
		sum += num[neg]; // add the mininum num  
	}
	for (int i = N - 1; i > neg; i--) { // other positive nums should be added after multiplied in decreasing order
		sum += num[i] * num[i - 1];
		i--;
	}

	cout << sum;

	return 0;
}
