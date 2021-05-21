/*
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.

Input Format :
first line of input will contain T number of tetst cases
Each input is consists of a single line containing a Integer n.

Output Format :
for each test case print all possible strings in different lines.

Constraints :
1 <= T <= 100
1 <= n <= 10^6

Sample Input:
1
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/

/* Sat-Chitta-Ananda */

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

const vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

vector<string> recursion(int n) {
	if(n <= 1) {
		return {""};
	}
	
	vector<string> ans = recursion(n / 10);
	vector<string> output;

	int index = n % 10;
	for(char c : keypad[index]) {
		for(string s : ans) {
			output.push_back(s + c);
		}
	}
	return output;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	vector<string> ans = recursion(n);

	for(string s : ans) {
		cout << s << '\n';
	}
	return 0;
}