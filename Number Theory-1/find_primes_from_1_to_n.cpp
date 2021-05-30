#include<bits/stdc++.h>
using namespace std;

const int N = 1000005;
bool sieve[N];

int main()
{
    for(int i = 0 ; i < N ; ++i) {
        sieve[i] = true;
    }
    sieve[0] = sieve[1] = false;
    
    for(int i = 2 ; i*i <= N ; ++i) {
        if(sieve[i]) {
            for(int j = i*i ; j < N ; j += i) {
                sieve[j] = false;
            }
        }
    }
    
    int n; cin >> n;
    
    int count = 0;
    for(int i = 0 ; i <= n ; ++i) {
        if(sieve[i]) ++count;
    }
    
    cout << count << '\n';
    
    return 0;
}