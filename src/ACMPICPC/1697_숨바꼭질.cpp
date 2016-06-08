#include <iostream>
#include <queue>
using namespace std;

int n, k;
int map[100003];
queue<int> q;

int sol()
{
	if (n == k) return 0;

	while (!q.empty()) {
		int here = q.front();
		q.pop();

		int next[3] = { here - 1, here + 1, here * 2 };
		for (int i = 0; i < 3; ++i) {
			int there = next[i];
			if (there >= 0 && there <= 100000 && map[there] == 0) {
				if (there == k) return map[here] + 1;
				q.push(there);
				map[there] = map[here] + 1;
			}
		}
	}
}

int main()
{
	cin >> n >> k;
	q.push(n);
	cout << sol() << endl;

	return 0;
}