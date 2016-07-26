#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_V = 20001;
const int INF = 987654321;

int V, E;
vector<pair<int, int> > graph[MAX_V];

vector<int> dijkstra(int src) {
	vector<int> dist(V, INF);
	dist[src] = 0;
	priority_queue<pair<int, int> > pq;
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
	return dist;
}

int main() {
	scanf("%d %d", &V, &E);
	int start, from, to, weight;
	scanf("%d", &start);
	for (int i = 0; i < E; ++i) {
		scanf("%d %d %d", &from, &to, &weight);
		graph[from - 1].push_back(make_pair(to - 1, weight));
	}

	vector<int> res = dijkstra(start - 1);
	for (int i = 0; i < res.size(); ++i) {
		if (res[i] == INF) printf("INF\n");
		else printf("%d\n", res[i]);
	}

	return 0;
}
