/*
Ayush loves the characters ‘a’, ‘s’, and ‘p’. He got a string of lowercase letters and he wants to find out how many times characters ‘a’, ‘s’, and ‘p’ occurs in the string respectively. Help him find it out.

Input:
First line contains an integer denoting length of the string.
Next line contains the string.

Constraints:
1<=n<=10^5
‘a’<= each character of string <= ‘z’

Output:
Three space separated integers denoting the occurrence of letters ‘a’, ‘s’ and ‘p’ respectively.

Sample Input:
6
aabsas
Sample output:
3 2 0
*/

/* Sat-Chitta-Ananda */

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	string s; cin >> s;

	unordered_map<int, int> hashMap;
	for(int i = 0 ; i < n ; ++i) {
		if(s[i] == 'a' || s[i] == 's' || s[i] == 'p') {
			hashMap[s[i]]++;
		}
	}

	cout << hashMap['a'] << ' ' << hashMap['s'] << ' ' << hashMap['p'] << '\n';
	return 0;
}