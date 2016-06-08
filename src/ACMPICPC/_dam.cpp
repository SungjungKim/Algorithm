/*
5
0 1 0 0 1
0 0 0 0 0
1 1 1 0 1
0 0 0 0 0
1 0 1 0 1
1 1
5

0 B 4 5 B
1 2 3 4 5
B B B 5 B
9 8 7 6 7
B 9 B 7 B

*/
#include <iostream>
#include <queue>
using namespace std;

int size, start_x, start_y, k;
int map[103][103];



int main()
{
	cin >> size;
	for (int i = 1; i <= size; ++i)
		for (int j = 1; j <= size; ++j)
			cin >> map[j][i];
	cin >> start_x >> start_y;
	cin >> k;

	return 0;
}