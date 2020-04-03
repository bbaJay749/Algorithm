#include <iostream>
#include <vector>
#include <string>
using namespace std;

int get_max(int a, int b) { return a > b ? a : b; };

int main() {
	string char1;
	string char2;

	cin >> char1 >> char2;

	int size1 = char1.size();
	int size2 = char2.size();

	vector<vector<int> > LCS(size1 + 1, vector<int>(size2 + 1, 0));

	for (int i = 1; i <= size1; i++) {
		for (int j = 1; j <= size2; j++) {
			if (char1[i - 1] == char2[j - 1]) LCS[i][j] = LCS[i - 1][j - 1] + 1;
			else LCS[i][j] = get_max(LCS[i - 1][j], LCS[i][j - 1]);
		}
	}

	cout << LCS[size1][size2] << endl;

	return 0;
}

/* idea from http://melonicedlatte.com/algorithm/2018/03/15/181550.html */
