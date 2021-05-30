/* Sat-Chitta-Ananda */

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

class Trie {
public:
	bool isEnd;
	Trie* child[2];

	Trie() {
		isEnd = false;
		child[0] = child[1] = NULL;
	}
};

void insert(Trie* root, int val) {
	Trie* current = root;
	for(int i = 31 ; i >= 0 ; --i) {
		int bit = ((val >> i) & 1);
		if(!current->child[bit]) {
			current->child[bit] = new Trie();
		}
		current = current->child[bit];
	}
	current->isEnd = true;
}

int query(Trie* root, int val) {
	Trie* current = root;
	int ans = 0;
	for(int i = 31 ; i >= 0 ; --i) {
		int bit = ((val >> i) & 1);
		if(current->child[1-bit]) {
			ans = ans | (1LL << i);
			current = current->child[1-bit];
		}
		else if(current->child[bit]) {
			current = current->child[bit];
		}
		else break;
	}
	return ans;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0 ; i < n ; ++i) {
		cin >> a[i];
	}

	int maxXorValue = a[0];

	Trie* root = new Trie();
	insert(root, a[0]);

	int currentXor = a[0];
	for(int i = 1 ; i < n ; ++i) {
		currentXor ^= a[i];
		int ans = query(root, currentXor);
		maxXorValue = max({maxXorValue, currentXor, ans});
		insert(root, currentXor);
	}

	cout << maxXorValue << '\n';

	return 0;
}