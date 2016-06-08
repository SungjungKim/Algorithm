#include <iostream>
#include <queue>
using namespace std;

const int INF = 100000;
int n, m;
int dir[4][2] = { -1, 0, 0, 1, 1, 0, 0, -1 };
int map[503][503] = { 0, };
int visit[503][503] = { 0, };
queue<int> qx, qy;

void print()
{
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

void sol(int x, int y, int* count)
{
	if (x < 1 || y < 1 || x > n || y > m) return;
	if (x == n && y == m) {
		(*count)++;
		return;
	}

	for (int i = 0; i < 4; ++i) {
		if (map[x][y] > map[x + dir[i][0]][y + dir[i][1]])
			sol(x + dir[i][0], y + dir[i][1], count);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i <= n + 1; ++i) {
		for (int j = 0; j <= m + 1; ++j) {
			map[i][j] = INF;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> map[i][j];
		}
	}
	int count = 0;
	sol(1, 1, &count);
	cout << count << endl;

	//print();
	return 0;
}