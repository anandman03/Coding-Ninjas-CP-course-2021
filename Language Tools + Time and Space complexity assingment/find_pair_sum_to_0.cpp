/*
Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
Note: Array A can contain duplicate elements as well.

Input format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.

Output format :
The first and only line of output contains the count of pair of elements in the array which sum up to 0. 

Constraints :
0 <= N <= 10^4
Time Limit: 1 sec

Sample Input 1:
5
2 1 -2 2 3
Sample Output 1:
2
*/

#include <bits/stdc++.h>
using namespace std;

int pairSum(int *arr, int n) {
	sort(arr, arr + n);

	unordered_map<int, int> frequency;
	for(int i = 0 ; i < n ; ++i) {
		frequency[arr[i]]++;
	}

	// array without duplicates
	vector<int> v;
	for(int i = 0 ; i < n ; ++i) {
		if(v.empty() || arr[i] != v.back()) {
			v.push_back(arr[i]);
		}
	}

	int count = 0;

	// if the a[i] == 0 first include those pairs
	if(frequency[0] > 0) {
		count += (frequency[0] * (frequency[0] - 1)) / 2;
	}

	int left = 0, right = v.size()-1;
	while(left < right) {
		if(v[left] + v[right] < 0) {
			++left;
		}
		else if(v[left] + v[right] > 0) {
			--right;
		}
		else {
			count += (frequency[v[left]] * frequency[v[right]]);
			--right;
			++left;
		}
	}
 	return count;
}