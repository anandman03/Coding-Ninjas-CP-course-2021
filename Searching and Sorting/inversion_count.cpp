#include <bits/stdc++.h>
using namespace std;

long long merge(long long* arr, int left, int mid, int right) {
    long long ans = 0;
    
    vector<long long> temp;
    int i = left, j = mid+1;
    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        }
        else {
            ans += (mid - i + 1);
            temp.push_back(arr[j++]);
        }
    }
    while(i <= mid) {
        temp.push_back(arr[i++]);
    }
    while(j <= right) {
        temp.push_back(arr[j++]);
    }
    
    for(int i = left ; i <= right ; ++i) {
        arr[i] = temp[i-left];
    }
    return ans;
}

long long divide(long long* arr, int left, int right) {
    if(left < right) {
        int mid = left + (right - left)/2;
        return divide(arr, left, mid) + divide(arr, mid+1, right) + merge(arr, left, mid, right);
    }
    return 0;
}

long long getInversions(long long *arr, int n) {
    return divide(arr, 0, n-1);
}