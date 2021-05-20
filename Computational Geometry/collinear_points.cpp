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
		int x1, y1; cin >> x1 >> y1;
		int x2, y2; cin >> x2 >> y2;
		int x3, y3; cin >> x3 >> y3;

		int determinant = x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2);

		if(determinant == 0) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}