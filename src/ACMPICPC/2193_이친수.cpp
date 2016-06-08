#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
int n;
vector<vector<ll> > cache;

// i��°�� ���� �ڸ��� c�� ��
ll rec(int i, int c)
{
	if (i == n) {
		if (c == 0) {	// ������ �� �ڸ��� 0�� ���, 01, 02 ����
			return 2;
		}
		else if (c == 1) {	// ������ �� �ڸ��� 1�� ���, 10�� ����
			return 1;
		}
	}

	ll &ret = cache[i][c];
	if (-1 != ret) return ret;

	if (c == 0) {	// ���� �ڸ� ���ڰ� 0�� ���
		ret = rec(i + 1, 0) + rec(i + 1, 1);
	}
	else {	// ���� �ڸ� ���ڰ� 1�� ���
		ret = rec(i + 1, 0);
	}

	return ret;
}

int main()
{
	cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	cache.assign(90, vector<ll>(90, -1));

	cout << rec(2, 1) << endl;

	return 0;
}