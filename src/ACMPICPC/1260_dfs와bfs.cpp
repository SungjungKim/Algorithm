/*
4 5 1
1 2
1 3
1 4
2 4
3 4

1 2 4 3
1 2 3 4
*/
#include <iostream>
#include <queue>
using namespace std;

int n, m, v;
int map[1111][1111] = { 0, };
int visit[1111] = { 0, };
queue<int> q;

void initVisit()
{
	for (int i = 1; i <= n; ++i)
		visit[i] = 0;
}

void dfs(int start)
{
	cout << start << " ";
	visit[start] = 1;
	for (int i = 1; i <= n; ++i) {
		// 연결된 간선이 있고, 아직 방문하지 않은 경우
		if (map[start][i] == 1 && visit[i] != 1)
			dfs(i);
	}
}

void bfs()
{
	int current;
	while (!q.empty()) {
		current = q.front();
		q.pop();
		cout << current << " ";

		for (int i = 1; i <= n; ++i) {
			// 연결된 간선이 있고, 아직 방문하지 않은 경우
			if (map[current][i] == 1 && visit[i] != 1) {
				q.push(i);
				visit[i] = 1;
			}
		}
	}
}

int main()
{
	cin >> n >> m >> v;
	int from, to;
	for (int i = 0; i < m; ++i) {
		cin >> from >> to;
		map[from][to] = map[to][from] = 1;
	}

	// dfs
	dfs(v);
	cout << endl;

	initVisit();
	// bfs
	q.push(v);
	visit[v] = 1;
	bfs();
	cout << endl;

	return 0;
}