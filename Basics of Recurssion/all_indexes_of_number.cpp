/*
Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
Do this recursively. Indexing in the array starts from 0.

Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x

Output Format :
indexes where x is present in the array (separated by space)

Constraints :
1 <= N <= 10^3

Sample Input :
5
9 8 10 8 8
8
Sample Output :
1 3 4
*/

int allIndexesHelper(int input[], int size, int x, int output[], int ptr, int index) {
	if(index == size) {
		return 0;
	}

	int ans = 0;
	if(input[index] == x) {
		ans = 1;
		output[ptr++] = index;
	}
	return ans + allIndexesHelper(input, size, x, output, ptr, index+1);
}

int allIndexes(int input[], int size, int x, int output[]) {
	return allIndexesHelper(input, size, x, output, 0, 0);
}