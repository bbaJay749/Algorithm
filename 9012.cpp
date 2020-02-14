#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stack>
using namespace std;

int check(stack<char> PS, char P[]){
	for(int i = 0; i < strlen(P); i++)
	{
		if(P[i] == '(') // '' for char, "" for string
		{
			PS.push('(');
		}
		else
		{
			if(PS.empty())
			{
				cout << "NO" << endl;
				return 0;
			}
			PS.pop();
		}
	}
	
	if(PS.empty()) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}

int main() {
	int n = 0;
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		stack<char> PS;
		char P[51];
		cin >> P;
		
		check(PS, P);
	}
	
	return 0;
}
