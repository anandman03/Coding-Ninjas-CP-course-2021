/* Sat-Chitta-Ananda */

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

void merge(vector<int>& a, int left, int mid, int right) {
	vector<int> t;
	int i = left, j = mid+1;
	while(i <= mid && j <= right) {
		if(a[i] <= a[j]) {
			t.push_back(a[i++]);
		}
		else {
			t.push_back(a[j++]);
		}
	}
	while(i <= mid) {
		t.push_back(a[i++]);
	}
	while(j <= right) {
		t.push_back(a[j++]);
	}
	
	for(int i = left ; i <= right ; ++i) {
		a[i] = t[i-left];
	}
}

void divide(vector<int>& a, int left, int right) {
	if(left < right) {
		int mid = (right + left) / 2;
		divide(a, left, mid);
		divide(a, mid+1, right);
		merge(a, left, mid, right);
	}
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		vector<int> a(n);
		for(int i = 0 ; i < n ; ++i) {
			cin >> a[i];
		}

		divide(a, 0, n-1);

		for(int i = 0 ; i < n ; ++i) {
			cout << a[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}