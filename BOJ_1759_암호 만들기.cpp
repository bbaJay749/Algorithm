#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C; 
vector<char> PW;

void dfs(int idx, vector<char> result, int counter) {
	if (counter == L) {
		int num_vowel = 0;
		int num_consonant = 0;

		for (int i = 0; i < L; i++) {
			char c = result[i];
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') num_vowel++;
			else num_consonant++;
		}

		if (num_vowel < 1 || num_consonant < 2) return;
		
		for (int i = 0; i < L; i++) {
			cout << result[i];
		}
		cout << "\n";

		return;
	}

	for (int i = idx; i < C; i++) {
		result.push_back(PW[i]);
		dfs(i + 1, result, counter + 1);
		result.pop_back();
	}
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> L >> C;

	char temp;
	for (int i = 0; i < C; i++) {
		cin >> temp;
		PW.push_back(temp);
	}

	sort(PW.begin(), PW.end(), less<char>());
	
	vector<char> result;
	dfs(0, result, 0);

	return 0;
}
