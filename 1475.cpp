#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int main() {
	int room_num[7] = {-1, -1, -1, -1, -1, -1, -1}, num_of_sets = 0;
	int nums[10] = { 0 };
	
	int size_of_num = 0;
	for (int i = 0; i < 7; i++) {
		scanf("%1d", &room_num[i]);	// read room number one by one
		if (room_num[i] == -1) break;	// 
		size_of_num++;
	}
	
	for (int i = 0; i < size_of_num; i++) {
		nums[room_num[i]] += 1;
	}
	
	if ((nums[6] + nums[9])%2 == 1){
		nums[6] = (nums[6] + nums[9]) / 2 + 1; // add num of 9s into 6s
	}
	else {
		nums[6] = (nums[6] + nums[9]) / 2;
	}
	nums[9] = 0;
	
	for (int i = 0; i < 10; i++) {
		if(nums[i] > num_of_sets){
			num_of_sets = nums[i];
		}
	}
	
	printf("%d", num_of_sets);

	return 0;
}
