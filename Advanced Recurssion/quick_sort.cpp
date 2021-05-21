/* Sat-Chitta-Ananda */

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

int partition(vector<int>& a, int left, int right) {
	int previousIndex = left - 1;
	for(int i = left ; i < right ; ++i) {
		if(a[i] < a[right]) {
			++previousIndex;
			swap(a[i], a[previousIndex]);
		}
	}
	swap(a[previousIndex+1], a[right]);
	return previousIndex+1;
}

void divide(vector<int>& a, int left, int right) {
	if(left < right) {
		int pivot = partition(a, left, right);
		divide(a, left, pivot-1);
		divide(a, pivot+1, right);
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