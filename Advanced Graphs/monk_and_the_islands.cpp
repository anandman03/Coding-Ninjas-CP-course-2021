/*
Monk visits the land of Islands. There are a total of N islands numbered from 1 to N. Some pairs of islands are connected to each other by Bidirectional bridges running over water.
Monk hates to cross these bridges as they require a lot of efforts. He is standing at Island #1 and wants to reach the Island #N. Find the minimum the number of bridges that he shall have to cross, if he takes the optimal route.

Input format:
First line contains T. T testcases follow.
First line of each test case contains two space-separated integers N, M.
Each of the next M lines contains two space-separated integers X and Y , denoting that there is a bridge between Island X and Island Y.

Output format:
Print the answer to each test case in a new line.

Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 10000
1 ≤ M ≤ 100000
1 ≤ X, Y ≤ N

Sample Input
2
3 2
1 2
2 3
4 4
1 2
2 3
3 4
4 2
Sample Output
2
2
*/

#include<bits/stdc++.h>
using namespace std;

int BFS(vector<vector<int>> graph,int n)
{
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++)
        visited[i] = false;

    int *level = new int[n];
    for(int i = 0; i < n; i++)
        level[i] = 0;
    
    queue<int> q;
    q.push(0);

    visited[0] = true;
 
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int i = 0; i < graph[v].size(); i++)
        {
            int next = graph[v][i];
            if(!visited[next])
            {
                q.push(next);
                visited[next] = true;
                level[next] = level[v] + 1;
            }
        }

    }
    return level[n-1];
}

int main()
{
	
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<vector<int>> graph(n);

        for(int i = 0; i < m; i++)
        {
            int a,b;
            cin >> a >> b;
            graph[a-1].push_back(b-1);
            graph[b-1].push_back(a-1);
        }

        int cost = BFS(graph,n);
        cout << cost << endl;
    }
	return 0;
}