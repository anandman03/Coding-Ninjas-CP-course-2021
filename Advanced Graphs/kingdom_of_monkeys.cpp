/* Sat-Chitta-Ananda */

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

class DSU {
private:
	vector<int> parent, rank;

public:
	DSU(int n) {
		for(int i = 0 ; i < n ; ++i) {
			rank.push_back(0);
			parent.push_back(i);
		}
	}

	int get_set(int x) {
		if(x == parent[x]) return x;
		return parent[x] = get_set(parent[x]);
	}

	void union_set(int x, int y) {
		x = get_set(x);
		y = get_set(y);
		if(x != y) {
			if(rank[x] == rank[y]) ++rank[x];
			if(rank[x] < rank[y]) swap(x, y);
			parent[y] = x;
		}
	}
};

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t--)
	{
		int n, m; cin >> n >> m;

		DSU dsu(n+1);

		for(int i = 0 ; i < m ; ++i) {
			int x, y;
			cin >> x >> y;
			dsu.union_set(x, y);
		}

		vector<int> a(n+1);
		for(int i = 1 ; i <= n ; ++i) cin >> a[i];

		unordered_map<int, int> hashMap;
		for(int i = 1 ; i <= n ; ++i) {
			hashMap[dsu.get_set(i)] += a[i];
		}

		int ans = 0;
		for(pair<int, int> p : hashMap) {
			ans = max(ans, p.second);
		}

		cout << ans << '\n';
	}
	return 0;
}