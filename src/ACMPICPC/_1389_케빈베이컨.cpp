#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int arr[7][7] = { 0, };
queue<int> qx, qy;

int sol()
{
	
}

int main()
{
	int x, y;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++ j) {
			cin >> x >> y;
			arr[x][y] = 1;
		}
	}



	return 0;
}