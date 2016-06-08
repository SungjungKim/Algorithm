/*
3
0 1 0
0 0 1
1 0 0
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
int visit[101];
int board[101][101] = { 0, };
int map[101][101] = { 0, };

void init()
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];
}

void printBoard()
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << map[i][j] << " ";
		cout << endl;
	}
}

void dfs(int v)
{
	for (int i = 0; i < n; ++i)
		if (board[v][i] == 1 && visit[i] == 0) {
			visit[i] = 1;
			dfs(i);
		}
}

void sol()
{
	for (int i = 0; i < n; ++i) {
		dfs(i);
		for (int j = 0; j < n; ++j) {
			map[i][j] = visit[j];
			visit[j] = 0;
		}
	}
}


int main()
{
	cin >> n;
	init();

	sol();

	printBoard();

	return 0;
}