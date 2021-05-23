/* Sat-Chitta-Ananda */

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

void BFS(vector<vector<int>>& graph, int startVertex, vector<bool>& visited) {
	queue<int> Queue;
	Queue.push(startVertex);
    visited[startVertex] = true;

	while(!Queue.empty()) {
		int node = Queue.front();
		Queue.pop();

		cout << node << ' ';
	
        for(int i = 0 ; i < graph[node].size() ; ++i) {
            if(!visited[i] && graph[node][i]) {
                Queue.push(i);
                visited[i] = true;
            }
        }
	}
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n, m; cin >> n >> m;
	
	vector<vector<int>> graph(n, vector<int>(n, 0));
	for(int i = 0 ; i < m ; ++i) {
		int x, y;
		cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
	}

	vector<bool> visited(n, false);

	for(int i = 0 ; i < n ; ++i) {
		if(!visited[i]) {
			BFS(graph, i, visited);
		}
	}

	return 0;
}