#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int T, N, result;
vector<pair<int, int> > F_men;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;

        int temp_first = 0, temp_second = 0, result = 0;
        for (int j = 0; j < N; j++) {
            cin >> temp_first >> temp_second;
            F_men.push_back({ temp_first, temp_second });
        }

        sort(F_men.begin(), F_men.end());    // sort with first value of the pairs
        result = 1; // the first F_man should be in the result
        int interviewRank = F_men[0].second; // the first F_man's second score

        for (int i = 1; i < N; i++) {
            if (F_men[i].second < interviewRank) {
                result++;
                interviewRank = F_men[i].second;
            }
        }

        cout << result << "\n";
        F_men = vector<pair<int, int> >();
    }

    return 0;
}

/* stupid way */
/*
#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int T, N;
vector<pair<int, int> > F_men;
vector<pair<int, int> > output;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;

        int temp_first = 0, temp_second = 0, result = 0;
        for (int j = 0; j < N; j++) {
            cin >> temp_first >> temp_second;
            F_men.push_back({ temp_first, temp_second });
        }

        for (int q = 0; q < N; q++) {
            output.push_back(F_men[q]);

            for (int k = 0; k < N; k++) {
                int temp_size = output.size();
                bool flag = true;

                int F_men_first = F_men[k].first;
                int F_men_second = F_men[k].second;
                for (int a = 0; a < temp_size; a++) {
                    int output_first = output[a].first;
                    int output_second = output[a].second;
                    if ((output_first >= F_men_first && output_second >= F_men_second) || (output_first < F_men_first && output_second < F_men_second)) {
                        flag = false;
                        break;
                    }
                }
                if (flag) output.push_back(F_men[k]);
            }

            if (result < output.size()) {
                result = output.size();
            }

            output = vector<pair<int, int> >();
        }

        cout << result << "\n";
        F_men = vector<pair<int, int> >();
    }

    return 0;
}
*/
