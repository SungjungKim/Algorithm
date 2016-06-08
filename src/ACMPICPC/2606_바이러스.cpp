#include <iostream>
using namespace std;

int visit[103] = { 0, };
int board[103][103] = { 0, };
int n, m, a, b;

void sol(int num)
{
	visit[num] = 1;
	for (int k = 1; k <= n; k++)
		if (visit[k] == 0 && board[num][k] == 1)
			sol(k);
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		board[a][b] = board[b][a] = 1;
	}

	sol(1);

	int count = -1;
	for (int i = 1; i <= n; i++)
		if (visit[i] == 1) 
			count++;
	cout << count << endl;

	return 0;
}
