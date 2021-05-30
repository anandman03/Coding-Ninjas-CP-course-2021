/* Sat-Chitta-Ananda */

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

const int N = (int) 1e6+5;
vector<bool> sieve;

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	sieve = vector<bool>(N, true);
	for(int i = 2 ; i*i <= N ; ++i) {
		if(sieve[i]) {
			for(int j = i*i ; j < N ; j += i) {
				sieve[j] = false;
			}
		}
	}

	int n; cin >> n;

	if(n <= 1) {
		cout << 1 << '\n';
	}
	else {
		cout << 2 << '\n';
	}

	int cp = 0, cnp = 0;
	for(int i = 2 ; i <= n+1 ; ++i) {
		if(sieve[i]) ++cp;
		else ++cnp;
	}

	cout << min(cp, cnp) << ' ' << max(cp, cnp) << '\n';

	return 0;
}