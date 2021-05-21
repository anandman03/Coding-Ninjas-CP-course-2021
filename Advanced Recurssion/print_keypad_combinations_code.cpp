/*
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.

Input Format :
Integer n

Output Format :
All possible strings in different lines

Constraints :
1 <= n <= 10^6

Sample Input:
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

#include <bits/stdc++.h>
using namespace std;

const vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void recursion(int n, string str) {
	if(n == 0) {
		cout << str << '\n';
		return;
	}
	
	int index = n % 10;
	if(index  <= 1) {
		recursion(n / 10, str);
	}

	string current = keypad[index];
	for(char c : current) {
		recursion(n / 10, c + str);
	}
}

void printKeypad(int num) {
    recursion(num, "");
}