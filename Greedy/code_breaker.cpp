/* Sat-Chitta-Ananda */

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

class Trie {
public:
	int index;
	unordered_map<char, Trie*> child;

	Trie() {
		index = -1;
		child = {};
	}
};

void insert(Trie* root, const string& s, const int& index) {
	Trie* current = root;
	for(char c : s) {
		if(!current->child.count(c)) {
			current->child[c] = new Trie();
		}
		current = current->child[c];
	}
	current->index = index;
}

string query(Trie* root, const int& id, const string& s) {
	Trie* current = root;
	string longestPrefix = "";
	for(char c : s) {
		if(!current->child.count(c)) {
			break;
		}
		longestPrefix += c;
		current = current->child[c];
	}

	if(current->index != -1) {
		return longestPrefix;
	}

	while(true) {
		for(char c = 'a' ; c <= 'z' ; ++c) {
			if(current->child.count(c)) {
				current = current->child[c];
				longestPrefix += c;
				
				if(current->index != -1) return longestPrefix;
			}
		}
	}
	return "";
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	Trie* root = new Trie();

	int n; cin >> n;
	for(int i = 0 ; i < n ; ++i) {
		string s; cin >> s;
		insert(root, s, i+1);
	}

	int q; cin >> q;
	while(q--) {
		int id; cin >> id;
		string s; cin >> s;
		cout << query(root, id, s) << '\n';
	}

	return 0;
}