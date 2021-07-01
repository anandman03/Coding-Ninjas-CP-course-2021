/* Sat-Chitta-Ananda */

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

class worker {
public:
	int time, cost, speed;
};

bool compare(worker a, worker b) {
	if(a.time == b.time) {
		if(a.speed == b.speed) return a.cost < b.cost;
		return a.speed > b.speed;
	}
	return a.time < b.time;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n, d;
	cin >> n >> d;

	worker a[n];
	for(int i = 0 ; i < n ; ++i) {
		cin >> a[i].time >> a[i].cost >> a[i].speed;
	}

	sort(a, a + n, compare);

	int bestSpeed = 0, minCost = 0;
	int areaCovered = 0, lastTime = 0;

	int index = 0;
	while(index < n) {
		// area covered by worker until we don't found next worker
		int currentArea = bestSpeed * (a[index].time - lastTime);
		areaCovered += currentArea;

		// if area covered, then stop
		if(areaCovered >= d) {
			break;
		}
		// if we find a worker with greater speed, hire him
		if(a[index].speed > bestSpeed) {
			bestSpeed = a[index].speed;
			minCost += a[index].cost;
		}
		lastTime = a[index].time;
		++index;
	}

	cout << minCost << '\n';
	return 0;
}
