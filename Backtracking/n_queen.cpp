/* Sat-Chitta-Ananda */

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

int a[11][11];

bool isSafe(int n, int row, int col) {
	for(int i = 0 ; i < row ; ++i) {
		if(a[i][col] == 1) return false;
	}
	for(int i = row-1, j = col-1 ; i >= 0 && j >= 0 ; --i, --j) {
		if(a[i][j] == 1) return false;
	}
	for(int i = row+1, j = col+1 ; i < n && j < n ; ++i, ++j) {
		if(a[i][j] == 1) return false;
	}
	for(int i = row-1, j = col+1 ; i >= 0 && j < n ; --i, ++j) {
		if(a[i][j] == 1) return false;
	}
	for(int i = row+1, j = col-1 ; i < n && j >= 0 ; ++i, --j) {
		if(a[i][j] == 1) return false;
	}
	return true;
}

void nQueen(int n, int row) {
	if(row == n) {
        for(int i = 0 ; i < n ; ++i) {
            for(int j = 0 ; j < n ; ++j) cout << a[i][j] << ' ';
        }
		cout << '\n';
		return;
	}

	for(int col = 0 ; col < n ; ++col) {
		if(isSafe(n, row, col)) {
			a[row][col] = 1;
			nQueen(n, row+1);
			a[row][col] = 0;
		}
	}
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	memset(a, 0, sizeof a);
    
	nQueen(n, 0);
	return 0;
}