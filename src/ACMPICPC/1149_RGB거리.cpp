#include <iostream>
using namespace std;

int N, INF = 987654321;
int memo[1001][3];
int arr[1001][3];

int min(int a, int b)
{
	if (a > b) return b;
	else return a;
}

int sol(int i, int color)
{
	int &ret = memo[i][color];
	if (i > N - 1)
		return 0;

	if (ret != 0)
		return ret;

	ret = INF;
	for (int c = 0; c < 3; c++)
		if (color != c)
			ret = min(ret, sol(i + 1, c) + arr[i][c]);

	return ret;
}

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

	cout << sol(-1, -1) << endl;

	return 0;
}