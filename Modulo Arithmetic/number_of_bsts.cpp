/* Sat-Chitta-Ananda */

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

const int MOD = (int) 1e9+7;

int memo(int n) {
	if(n <= 1) return 1;

	int x = memo(n-1);
	int y = memo(n-2);

	return ((x * x) % MOD + (2LL * x * y) % MOD) % MOD;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;

		cout << memo(n) << '\n';
	}
	return 0;
}