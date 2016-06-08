#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
string line;
int map[51][51];

void print()
{
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << map[j][i] << " ";
		}
		cout << endl;
	}
}

// (x, y)		(temp_x, y)
// (x, temp_y)	(temp_x, temp_y) 
// 왼쪽 상단의 좌표가 x, y이고 크기가 size인 정사각형의 꼭지점 수가 모두 같을 경우 true
bool isSame(int x, int y, int size)
{
	int temp_x = x + size - 1, temp_y = y + size - 1;
	if (map[y][x] == map[y][temp_x] && map[y][x] == map[temp_y][x] && map[y][x] == map[temp_y][temp_x])
		return true;
	return false;
}

int search(int size)
{
	int maxValue = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i + size - 1 <= n && j + size - 1 <= m) {
				if (isSame(i, j, size)) {
					if (maxValue < size * size) {
						maxValue = size * size;
					}
				}
			}
		}
	}

	return maxValue;
}



int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> line;
		for (int j = 1; j <= m; ++j) {
			map[j][i] = line.at(j - 1) - '0';
		}
	}

	// print();

	int maxValue = 0, maxSize = min(n, m);
	for (int i = 1; i <= maxSize; ++i) {
		int area = search(i);
		if (maxValue < area) {
			maxValue = area;
		}
	}

	cout << maxValue << endl;

	return 0;
}