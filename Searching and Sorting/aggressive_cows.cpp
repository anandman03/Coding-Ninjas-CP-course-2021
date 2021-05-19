/* Sat-Chitta-Ananda */

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf (int)1e9
#define f first
#define s second

bool check(const vector<int>& a, const int& cows, int distance) {
	int count = 1;
	int previousPosition = 0; //place a cow at first position.
	for(int i = 1 ; i < a.size() ; ++i) {
		if(a[i] - a[previousPosition] >= distance) {
			++count;
			previousPosition = i;
		}
		if(count >= cows) return true;
	}
	return false;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t--)
	{
		int n, c;
		cin >> n >> c;

		vector<int> a(n);
		for(int i = 0 ; i < n ; ++i) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());

		int left = 0;
		int right = 1000000001;

		int ans = 0;

		while(left <= right) {
			int mid = (right + left) / 2;
			if(check(a, c, mid)) {
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