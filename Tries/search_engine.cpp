/* Sat-Chitta-Ananda */

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

class Trie {
public:
	bool isEnd;
	int weight;
	unordered_map<char, Trie*> child;

	Trie() {
		child = {};
		weight = 0;
		isEnd = false;
	}
};

void insert(Trie* root, const string& s, int& wt) {
	Trie* current = root;
	for(char c : s) {
		if(!current->child.count(c)) {
			current->child[c] = new Trie();
		}
		current = current->child[c];
		current->weight = max(current->weight, wt);
	}
	current->isEnd = true;
}

int query(Trie* root, const string& s) {
	Trie* current = root;
	for(char c : s) {
		if(!current->child.count(c)) {
			return -1;
		}
		current = current->child[c];
	}
	
	int ans = -1;
	for(char c = 'a' ; c <= 'z' ; ++c) {
		if(current->child.count(c)) {
			ans = max(ans, current->child[c]->weight);
		}
	}
	return ans;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	Trie* root = new Trie();

	int n, q;
	cin >> n >> q;
	for(int i = 0 ; i < n ; ++i) {
		string s; cin >> s;
		int value; cin >> value;
		insert(root, s, value);
	}

	while(q--) {
		string s; cin >> s;
		cout << query(root, s) << '\n';
	}
	return 0;
}