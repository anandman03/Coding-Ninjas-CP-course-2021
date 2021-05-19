/* Sat-Chitta-Ananda */

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

int merge(vector<int>& a, int left, int mid, int right) {
	int ans = 0;

	vector<int> temp;
	int i = left, j = mid+1;
	while(i <= mid && j <= right) {
		if(a[i] < a[j]) {
			ans += (a[i] * (right - j + 1));
			temp.push_back(a[i++]);
		}
		else {
			temp.push_back(a[j++]);
		}
	}
	while(i <= mid) {
		temp.push_back(a[i++]);
	}
	while(j <= right) {
		temp.push_back(a[j++]);
	}

	for(int i = left ; i <= right ; ++i) {
		a[i] = temp[i-left];
	}
	return ans;
}

int divide(vector<int>& a, int left, int right) {
	if(left < right) {
		int mid = left + (right - left) / 2;
		return divide(a, left, mid) + divide(a, mid+1, right) + merge(a, left, mid, right);
	}
	return 0;
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

		cout << divide(a, 0, n-1) << '\n';
	}
	return 0;
}