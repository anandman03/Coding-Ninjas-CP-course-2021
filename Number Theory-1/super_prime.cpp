#include<bits/stdc++.h>
using namespace std;

const int N = 1000005;
long long sieve[N];

int main()
{
    for(int i = 0 ; i < N ; ++i) {
        sieve[i] = 0;
    }
    
    for(int i = 2 ; i < N ; ++i) {
        if(!sieve[i]) {
            for(int j = 2*i ; j < N ; j += i) {
                ++sieve[j];
            }
        }
    }
    
    int n; cin >> n;
    
    int count = 0;
    for(int i = 0 ; i <= n ; ++i) {
        if(sieve[i] == 2) ++count;
    }
    
    cout << count << '\n';
    
    return 0;
}