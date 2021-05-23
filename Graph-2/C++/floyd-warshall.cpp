/* Sat-Chitta-Ananda */

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;

		vector<vector<int>> dp(102, vector<int>(102, INT_MAX));

		for(int i = 0 ; i < m ; ++i) {
			int x, y, z;
			cin >> x >> y >> z;
			dp[x][y] = dp[y][x] = min(dp[x][y], z);
		}

		for(int i = 0 ; i <= n ; ++i) {
			dp[i][i] = 0;
		}

		for(int k = 1 ; k <= n ; ++k) {
			for(int i = 1 ; i <= n ; ++i) {
				for(int j = 1 ; j <= n ; ++j) {
					if(dp[i][k] != INT_MAX && dp[k][j] != INT_MAX) {
						dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
					}
				}
			}
		}

		int q; cin >> q;
		while(q--) {
			int x, y; 
			cin >> x >> y;
			cout << dp[x][y] << '\n';
		}
	}
	return 0;
}