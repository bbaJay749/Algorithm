/*  Backtracking should be check before call the func */

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef struct {
	int x, y;
}Pos;

typedef struct {
	double PE, PW, PS, PN;
}EWSN;

void calPS(bool **plain, Pos loc, EWSN EWSN, int N, int count, double possiblity);
double possiblity = 0;

int main() {
	int N = 0;
	EWSN EWSN;
	cin >> N >> EWSN.PE >> EWSN.PW >> EWSN.PS >> EWSN.PN;

	EWSN.PE /= 100; EWSN.PW /= 100; EWSN.PS /= 100; EWSN.PN /= 100;

	bool **plain = new bool*[2 * N + 1];
	for (int i = 0; i < 2 * N + 1; i++) {
		plain[i] = new bool[2 * N + 1];
		memset(plain[i], false, sizeof(bool) * (2 * N + 1));
	}
    
	Pos origin = { N, N };
    	plain[origin.x][origin.y] = 1;
	
	calPS(plain, origin, EWSN, 2 * N, N, 1);

	cout << fixed;
	cout.precision(10);
	cout << possiblity;

	return 0;
}

void calPS(bool **plain, Pos loc, EWSN EWSN, int N, int count, double temp_possiblity) {
	if (count <= 0) {
		possiblity += temp_possiblity;
		return;
	}

	if (temp_possiblity != 0) {
		if (loc.x < N && plain[loc.x + 1][loc.y] == 0) {   // E
            		plain[loc.x + 1][loc.y] = 1;
			loc.x++;
			calPS(plain, loc, EWSN, N, count - 1, temp_possiblity * EWSN.PE);
			loc.x--;
            		plain[loc.x + 1][loc.y] = 0;
		}
		if (loc.x > 0 && plain[loc.x - 1][loc.y] == 0) {   // W
            		plain[loc.x - 1][loc.y] = 1;
			loc.x--;
			calPS(plain, loc, EWSN, N, count - 1, temp_possiblity * EWSN.PW);
			loc.x++;
            		plain[loc.x - 1][loc.y] = 0;
		}
		if (loc.y > 0 && plain[loc.x][loc.y - 1] == 0) {   // S
            		plain[loc.x][loc.y - 1] = 1;
			loc.y--;
			calPS(plain, loc, EWSN, N, count - 1, temp_possiblity * EWSN.PS);
			loc.y++;
            		plain[loc.x][loc.y - 1] = 0;
		}
	 	if (loc.y < N && plain[loc.x][loc.y + 1] == 0) {   // N
     	  	        plain[loc.x][loc.y + 1] = 1;
			loc.y++;
			calPS(plain, loc, EWSN, N, count - 1, temp_possiblity * EWSN.PN);
			loc.y--;
            		plain[loc.x][loc.y + 1] = 0;
		}
	}
}
