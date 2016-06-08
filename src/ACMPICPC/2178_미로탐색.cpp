#include <iostream>
#include <string>
#include <queue>
using namespace std;

string s;
int n, m, c;
int visit[103][103] = { 0, };
int board[103][103] = { 0, };
int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };

queue<int> qx, qy;

void init()
{
	for (int i = 1; i <= n; ++i) {
		cin >> s;
		for (int j = 1; j <= m; ++j) {
			board[i][j] = s.at(j - 1) - 48;
		}
	}
}

void print()
{
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << visit[i][j] << " ";
		}
		cout << endl;
	}
}

void sol(int x, int y)
{
	while (!qx.empty() && !qy.empty()) {
		int x, y;
		x = qx.front();
		y = qy.front();
		qx.pop(); qy.pop();

		int count = visit[x][y];

		if (x == n && y == m) {
			cout << count << endl;
			return;
		}

		for (int i = 0; i < 4; ++i){
			if (board[x + dir[i][0]][y + dir[i][1]] == 1 && visit[x + dir[i][0]][y + dir[i][1]] == 0) {
				qx.push(x + dir[i][0]);
				qy.push(y + dir[i][1]);
				visit[x + dir[i][0]][y + dir[i][1]] = count + 1;
			}
		}
	}

	return;
}

int main()
{
	cin >> n >> m;
	init();
	qx.push(1);
	qy.push(1);
	visit[1][1] = 1;
	sol(1, 1);

	//print();

	return 0;
}