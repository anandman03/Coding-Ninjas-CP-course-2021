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
		int n; cin >> n;

		vector<int> x(n), y(n);
		for(int i = 0 ; i < n ; ++i) {
			cin >> x[i] >> y[i];
		}

		double area = 0.0;

		for(int i = 1 ; i < n-1 ; ++i) {
			double x1 = x[i] - x[0];
			double y1 = y[i] - y[0];
			double x2 = x[i+1] - x[0];
			double y2 = y[i+1] - y[0];

			area += (x1 * y2) - (y1 * x2);
		}

		cout << (int) abs(area)/2 << '\n';
	}
	return 0;
}