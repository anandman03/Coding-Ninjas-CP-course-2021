/* Sat-Chitta-Ananda */

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

class Trie {
public:
	bool isEnd;
	vector<Trie*> child;

	Trie() {
		isEnd = false;
		child = vector<Trie*>(2, NULL);
	}
};

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	Trie* root = new Trie();

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for(int i = 0 ; i < n ; ++i) {
		cin >> a[i];
	}

	
	return 0;
}