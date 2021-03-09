#include <stack>
#include <iostream>
#include <string>
using namespace std;

int main() {
	for (int k = 1; ; k++) {
		string s; 
		int count = 0; 
		stack<char> brackets;

		cin >> s;

		if (s[0] == '-') { 
			return 0;
		}

		for (int i = 0; i < s.size(); i++) { 
			if (brackets.size() == 0 && s[i] == '}') {	// if there are no { and } comes in
				count++; 
				s[i] == '{'; // change } into {, push
				brackets.push(s[i]); 
			}
			else if (brackets.size() != 0 && s[i] == '}') { // if there are some { and } comes in, pop
				brackets.pop(); 
			}
			else { // if {, push
				brackets.push(s[i]); 
			}
		}

		count += brackets.size() / 2; // add leftover/2 into count

		cout << k << ". " << count << '\n';
	}

	return 0;
}
