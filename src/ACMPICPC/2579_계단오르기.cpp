/*
6
10
20
15
25
10
20
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr;
vector<vector<int> > cache;

// step�� here �ܰ迡�� �������� step�� ����� �� �ִ� ����
int rec(int here, int step)
{
	// 3�� ���� ��Ұų� ������ ���� ���� ���
	if (step >= 3 || here < 0) return 0;

	int &ret = cache[here][step];
	if (-1 != ret) return ret;

	int one = arr[here] + rec(here - 1, step + 1);	// �� ĭ ������ ���
	int two = arr[here] + rec(here - 2, 1);			// �� ĭ ������ ���
	ret = max(one, two);

	return ret;
}

int main()
{
	cin >> n;
	int score;
	for (int i = 0; i < n; ++i) {
		cin >> score;
		arr.push_back(score);
	}
	cache.assign(n + 1, vector<int>(3, -1));

	// ������ ����� ������ ��ƾ� �ϹǷ� ������ ��ܺ��� ���
	cout << rec(n - 1, 1) << endl;

	return 0;
}