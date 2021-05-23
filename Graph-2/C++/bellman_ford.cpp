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

		int a, b;
		cin >> a >> b;

		vector<vector<int>> g;
		for(int i = 0 ; i < m ; ++i) {
			int x, y, z;
			cin >> x >> y >> z;
			g.push_back({x, y, z});
		}

		vector<int> distance(n+1, INT_MAX);
		distance[a] = 0;

		for(int i = 1 ; i <= n ; ++i) {
			for(int j = 0 ; j < m ; ++j) {
				int src = g[j][0];
				int dst = g[j][1];
				int val = g[j][2];
				if(distance[src] != INT_MAX && distance[dst] > distance[src] + val) {
					distance[dst] = distance[src] + val;
				}
			}
		}

		if(distance[b] == INT_MAX) {
			distance[b] = (int) 1e9;
		}
		cout << distance[b] << '\n';
	}
	return 0;
}