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

		vector<vector<pair<int, int>>> a(n);
		for(int i = 0 ; i < m ; ++i) {
			int x, y, z;
			cin >> x >> y >> z;
			a[x].push_back({z, y});
			a[y].push_back({z, x});
		}

		vector<bool> visited = vector<bool>(n, false);
		vector<int> weight = vector<int>(n, INT_MAX);
		weight[0] = 0;

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
		q.push({0, 0});

		while(!q.empty()) {
			int currentWeight = q.top().first;
			int currentNode = q.top().second;
			q.pop();

			visited[currentNode] = true;

			for(pair<int, int> x : a[currentNode]) {
				int node = x.second;
				int value = x.first;
				if(!visited[node] && weight[node] > value) {
					weight[node] = value;
					q.push({value, node});
				}
			}
		}

		int ans = 0;
		for(int x : weight) ans += x;

		cout << ans << '\n';
	}
	return 0;
}