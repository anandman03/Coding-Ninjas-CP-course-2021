/*
In Little Flowers Public School, there are many students with same first names. You are given a task to find the students with same names. You will be given a string comprising of all the names of students and you have to tell the name and count of those students having same. If all the names are unique, print -1 instead.
Note: We don't have to mention names whose frequency is 1.

Input Format:
The only line of input will have a string ‘str’ with space separated first names of students.

Output Format:
Print the names of students along with their count if they are repeating. If no name is repeating, print -1

Constraints:
1 <= |str| <= 10^5
Time Limit: 1 second

Sample Input 1:
Abhishek harshit Ayush harshit Ayush Iti Deepak Ayush Iti
Sample Output 1:
harshit 2
Ayush 3
Iti 2

Sample Input 2:
Abhishek Harshit Ayush Iti
Sample Output:
-1
*/

/* Sat-Chitta-Ananda */

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string s;
	getline(cin, s);

	// spliting string
	vector<string> v;
	stringstream stream(s);
	string stringStreamBuffer;
	while(getline(stream, stringStreamBuffer, ' ')) {
		v.push_back(stringStreamBuffer);
	}

	unordered_map<string, int> frequency;
	for(int i = 0 ; i < v.size() ; ++i) {
		frequency[v[i]]++;
	}

	// check if all are unique
	int count = 0;
	for(int i = 0 ; i < v.size() ; ++i) {
		if(frequency[v[i]] > 1) ++count;
	}

	// all names are unique
	if(count == 0) {
		cout << -1 << '\n';
	}
	else {
		for(pair<string, int> p : frequency) {
			if(p.second > 1) {
				cout << p.first << ' ' << p.second << '\n';
			}
		}
	}
	return 0;
}