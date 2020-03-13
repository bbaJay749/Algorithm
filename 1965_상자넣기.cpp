#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int* box = new int[N];
	for (int n = 0; n < N; n++) {
		cin >> box[n];
	}

	int* arr = new int[N];	// arr is the maximum num of boxes at current location 
	int max_box = 0;	// max_box is the maximum num of boxes can be put
	arr[0] = 1;
	for (int i = 1; i < N; i++) {
		int tmp = 0; // to get the max num among the prior boxes of current location
		for (int j = 0; j < i; j++) { // check all the prior boxes 
			if (box[j] < box[i] && arr[j] > tmp) { 
				// if prior box is smaller than current one and has more boxes than other ones
				tmp = arr[j];
			}
		}
		arr[i] = tmp + 1; // to include current box
		if (arr[i] > max_box) {
			max_box = arr[i]; // save the max value
		}
	}

	cout << max_box;

	return 0;
}
