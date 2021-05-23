/*
You all must be familiar with the chess-board having 8 x 8 squares of alternate black and white cells. Well, here we have for you a similar N x M size board with similar arrangement of black and white cells.
A few of these cells have Horses placed over them. Each horse is unique. Now these horses are not the usual horses which could jump to any of the 8 positions they usually jump in. They can move only if there is another horse on one of the 8-positions that it can go to usually and then both the horses will swap their positions. This swapping can happen infinitely times.
A photographer was assigned to take a picture of all the different ways that the horses occupy the board! Given the state of the board, calculate answer. Since this answer may be quite large, calculate in modulo 10^9+7.

Input Format:
First line contains T which is the number of test cases.
T test cases follow first line of each containing three integers N, M and Q where N,M is the size of the board and Q is the number of horses on it.
Q lines follow each containing the 2 integers, X and Y which are the coordinates of the Horses.

Output format:
For each test case, output the number of photographs taken by a photographer in new line.

Constraints:
 1<=T<=10
 1<=N,M<=1000
 1<=Q<=N*M
Sample Input:
2
4 4 4
1 1
1 2
3 1
3 2
4 4 4
1 1
1 2
3 1
4 4
Sample Output:
4
2
*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[8] = {1, -1, -2, -2, -1, 1, 2, 2};

ll DFS(vector<vector<int>>& board, const int& n, const int& m, int x, int y) {
    board[x][y] = 2;
    
    ll ans = 1;
    for(int i = 0 ; i < 8 ; ++i) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(tx >= 0 && ty >= 0 && tx < n && ty < m && board[tx][ty] == 1) {
            ans = (ans + DFS(board, n, m, tx, ty)) % MOD;
        }
    }
    return ans % MOD;
}

int main()
{
    const int N = 1000000;
    
    vector<ll> factorial(N, 1);
    for(ll i = 2; i < 1000000; i++) {
        factorial[i] = (factorial[i-1] * i) % MOD;
    }
    
    int t;
    cin >> t;
    while(t--) {
        ll n, m, q;
        cin >> n >> m >> q;
		
        vector<vector<int>> board(n, vector<int>(m, 0));
        for(int i = 0; i < q; ++i) {
            int x, y;
            cin >> x >> y;
            board[x-1][y-1] = 1;
        }
		
        ll ans = 1;
        for(int i = 0 ; i < n ; ++i) {
            for(int j = 0 ; j < m ; j++) {
                if(board[i][j] == 1) {
                    ll val = DFS(board, n, m, i, j);
                    ans = (ans * factorial[val]) % MOD;
                }
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}