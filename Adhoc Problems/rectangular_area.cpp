/* Sat-Chitta-Ananda */

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	vector<int> x(n), y(n);
	for(int i = 0 ; i < n ; ++i) {
		cin >> x[i] >> y[i];
	}

	int maxX = *max_element(x.begin(), x.end()) / 2;

	int N = (int) 5e6+2;
	vector<int> height(N, 0);
	for(int i = 0 ; i < n ; ++i) {
		height[x[i] / 2] = max(height[x[i] / 2], y[i]);
	}

	int area = 0;

	for(int i = maxX ; i > 0 ; --i) {
		if(height[i] < height[i+1]) {
			height[i] = height[i+1];
		}
		area += height[i];
	}

	cout << 2LL*area << '\n';

	return 0;
}