/* Sat-Chitta-Ananda */

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string s; cin >> s;
	const int n = s.size();

	vector<int> points(n);
	for(int i = 0 ; i < n ; ++i) {
		cin >> points[i];
	}

	int ans = 0;

	vector<int> x(n+1, 0), y(n+1, 0);
	for(int i = 0 ; i < n ; ++i) {
		x[i+1] = x[i];
		y[i+1] = y[i];

		if(s[i] == 'N') {
			y[i+1] = y[i] + points[i];
		}
		if(s[i] == 'S') {
			y[i+1] = y[i] - points[i];
		}
		if(s[i] == 'E') {
			x[i+1] = x[i] + points[i];
		}
		if(s[i] == 'W') {
			x[i+1] = x[i] - points[i];
		}
		ans += (x[i+1] - x[i]) * y[i];
	}

	cout << abs(ans) << '\n';

	return 0;
}