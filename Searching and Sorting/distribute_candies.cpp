/* Sat-Chitta-Ananda */

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

bool check(const vector<int>& a, int candies, const int& k) {
	int countChildren = 0;
	for(int i = 0 ; i < a.size() ; ++i) {
		countChildren += a[i] / candies;
		if(countChildren >= k) return true;
	}
	return false;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;

		vector<int> a(n);
		for(int i = 0 ; i < n ; ++i) {
			cin >> a[i];
		}

		int ans = 0;

		int left = 0, right = (int) 1e9;
		while(left <= right) {
			int mid = left + (right - left) / 2;
			if(check(a, mid, k)) {
				ans = mid;
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}