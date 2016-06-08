#include <iostream>
using namespace std;

int n, m;
const int INF = 987654321;
int via[101][101] = { 0, };
int board[101][101] = { 0, };

void sol()
{
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) board[i][j] = 0;
				if (board[i][j] > board[i][k] + board[k][j]) {
					board[i][j] = board[i][k] + board[k][j];
					via[i][j] = k;
				}
			}
		}
	}
}

void printBoard()
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	// init
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			via[i][j] = INF;
	for (int i = 0; i < m; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		if (via[a][b] > cost)
			via[a][b] = cost;
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			board[i][j] = via[i][j];

	sol();
	printBoard();
	
}