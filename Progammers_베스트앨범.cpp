#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int> genres_count;
	vector <pair<string, int>> v;

	// count genre by genre
	for (int i = 0; i < genres.size(); i++) {
		genres_count[genres[i]] += plays[i];
	}

	map<string, int>::iterator iter = genres_count.begin();
	for (iter = genres_count.begin(); iter != genres_count.end(); ++iter) {
		v.push_back({ iter->first, iter->second });
	}	// save all the map in vector

	sort(v.begin(), v.end(), cmp); // sort with num of play
	for (int i = 0; i < v.size(); i++)	// find top 2 song per genre
	{ 
		int top_num = 0; int _2nd_top_num = 0; int top_idx = 0; int _2nd_top_idx = 0;
		for (int j = 0; j < genres.size(); j++) {
			if (genres[j] == v[i].first) {
				if (plays[j] > top_num) {
					_2nd_top_num = top_num;
					_2nd_top_idx = top_idx;
					top_num = plays[j];
					top_idx = j;
				}
				else if (plays[j] > _2nd_top_num) {
					_2nd_top_num = plays[j];
					_2nd_top_idx = j;
				}
			}
		}
		answer.push_back(top_idx);

		if (_2nd_top_num > 0) {
			answer.push_back(_2nd_top_idx);
		} // only when there are 2+ songs in genre
	}
	return answer;
}

/* revised from https://greenapple16.tistory.com/86 */