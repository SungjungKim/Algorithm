#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
const int MAX_V = 1001;
const int INF = 987654321;

int V, E;
vector<pair<int, ull> > graph[MAX_V];

int dijkstra(int src, int dest) {
	vector<int> dist(V, INF);
	dist[src] = 0;
	priority_queue<pair<ull, int> > pq;
	pq.push(make_pair(0, src));
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost) continue;

		for (int i = 0; i < graph[here].size(); ++i) {
			int there = graph[here][i].first;
			int nextDist = cost + graph[here][i].second;
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}

	return dist[dest];
}


int main() {
    scanf("%d %d", &V, &E);
    int from, to; ull weight;
    for (int i = 0; i < E; ++i) {
        scanf("%d %d %lld", &from, &to, &weight);
        graph[from - 1].push_back(make_pair(to - 1, weight));
    }

    int src, dest;
    scanf("%d %d", &src, &dest);
    printf("%d\n", dijkstra(src - 1, dest - 1));

    return 0;
}
