#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int num_of_nums = 0;
	int sum = 0;

	cin >> num_of_nums;

	int* nums = new int[num_of_nums]();

	for (int i = 0; i < num_of_nums; i++) {
		scanf("%1d", &nums[i]);
	}
	
	for (int i = 0; i < num_of_nums; i++) {
		sum += nums[i];
	}

	delete[] nums;

	cout << sum;

	return 0;
}
