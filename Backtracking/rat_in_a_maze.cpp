/* Sat-Chitta-Ananda */

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

int maze[20][20], solution[20][20];

bool isSafe(int row, int col, int n) {
	return (row >= 0 && col >= 0 && row < n && col < n && maze[row][col] == 1 && solution[row][col] == 0);
}

void runRat(int row, int col, int n) {
	if(!isSafe(row, col, n)) {
		return;
	}
    
	if(row == n-1 && col == n-1) {
        solution[row][col] = 1;
		for(int i = 0 ; i < n ; ++i) {
			for(int j = 0 ; j < n ; ++j) cout << solution[i][j] << ' ';
		}
		cout << '\n';
        solution[row][col] = 0;
        return;
	}
	
    solution[row][col] = 1;
    
    runRat(row-1, col, n);
	runRat(row+1, col, n);
    runRat(row, col-1, n);
	runRat(row, col+1, n);

	solution[row][col] = 0;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n; cin >> n;

	for(int i = 0 ; i < n ; ++i) {
		for(int j = 0 ; j < n ; ++j) cin >> maze[i][j];
	}
	memset(solution, 0, sizeof solution);

	runRat(0, 0, n);
	return 0;
}