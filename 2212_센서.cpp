#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, tmp;
vector<int> sensor;
vector<int> gap;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		sensor.push_back(tmp);
	}

	sort(sensor.begin(), sensor.end());

	/* get the diff between each sensors */
	for (int i = 1; i < N; i++) {
		gap.push_back(sensor[i] - sensor[i - 1]);
	} 

	sort(gap.begin(), gap.end(), greater<int>()); 

	int area = sensor[N - 1] - sensor[0]; // diff between the first & last sensor
	for (int i = 0; i < K - 1; i++) { // need to split up at the point where the diff. between sensors are large
		if (i >= N - 1) { // if num of centers > num of sensors, stop making more center
			break;
		}
		area -= gap[i]; // spliting up means the gap between two sensors = 0
	}

	cout << area;

	return 0;
}
