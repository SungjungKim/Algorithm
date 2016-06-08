#include <iostream>
#include <string>
using namespace std;

int x, y;
string day[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
string arr[13][32];

// 1, 3, 5, 7, 8, 10, 12���� 31�ϱ���, 4, 6, 9, 11���� 30�ϱ���, 2���� 28��
void init()
{
	int dayNum = 0;

	for (int i = 1; i <= 12; ++i) {
		for (int j = 1; j <= 31; ++j) {
			if (i == 2) {
				if (j == 29) break;
				arr[i][j] = day[dayNum++ % 7];
			}
			else if (i == 4 || i == 6 || i == 9 || i == 11) {
				if (j == 31) break;
				arr[i][j] = day[dayNum++ % 7];
			}
			else {
				arr[i][j] = day[dayNum++ % 7];
			}
		}
	}
}

int main()
{
	cin >> x >> y;

	init();
	cout << arr[x][y] << endl;

	return 0;
}