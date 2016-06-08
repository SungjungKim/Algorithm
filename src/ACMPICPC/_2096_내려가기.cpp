#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;
int n;
int arr[10003][5] = { 0, };
int brr[10003][5];

int max(int a, int b, int c)
{
	if (a > b) {
		if (b > c) return a;
		else { // c > b
			if (a > c) return a;
			else return c;
		}
	}
	else { // b >a
		if (a > c) return b;
		else { // c >a
			if (b > c) return b;
			else return c;
		}
	}
}

int min(int a, int b, int c)
{
	if (a > b) {
		if (b > c) return c;
		else { // c > b
			return b;
		}
	}
	else { // b > a
		if (a > c) return c;
		else { // c > a
			return a;
		}
	}
}

void sol()
{
	int maxValue = 0, minValue = INF;
	int maxTemp = 0, minTemp = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 3; ++j) {
			maxTemp = max(arr[i - 1][j - 1], arr[i - 1][j], arr[i - 1][j + 1]);
			arr[i][j] += maxTemp;
			maxValue = max(maxValue, arr[i][j], 0);
			
			minTemp = min(brr[i - 1][j - 1], brr[i - 1][j], brr[i - 1][j + 1]);
			brr[i][j] += minTemp;
			minValue = min(minValue, brr[i][j], INF);
		}
	}

	cout << maxValue << " " << minValue << endl;
}

int main()
{
	cin >> n;
	for (int i = 0; i <= n + 1; ++i) {
		for (int j = 0; j <= 4; ++j) {
			brr[i][j] = INF;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 3; ++j) {
			cin >> arr[i][j];
			brr[i][j] = arr[i][j];
		}
	}



	sol();

	return 0;
}