#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int> > flowers;
int M_start, D_start, M_end, D_end;
int result;
bool flag = false;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> M_start >> D_start >> M_end >> D_end;
		flowers.push_back({ M_start * 100 + D_start, M_end * 100 + D_end });
	}

	sort(flowers.begin(), flowers.end());


	int req_date = 301;
	int temp_date = 0; 
	int index = -1;

	/* from 03.01 to 11.30 || 'til scan all the flowers */
	while (req_date <= 1130 && index < N) {
		flag = false; 
		index++;

		/* scan all the flower from index i */
		for (int j = index; j < N; j++) {
			/* if the flower has later start date than current date which has to be filled, break */
			if (flowers[j].first > req_date) break;
			/* if the flower has later end date than temp_date, change temp into it and change index into j */
			if (temp_date < flowers[j].second) {
				temp_date = flowers[j].second;
				flag = true;
				index = j;
			}
		}

		/* if flower has chosen, change the start date and result++ */
		if (flag) {
			req_date = temp_date;
			result++;
		} 
		/* if it's not possible */
		else {
			cout << "0\n";
			return 0;
		}
	}
	
	cout << result << "\n";

	return 0;
}
