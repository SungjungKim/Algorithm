#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;
vector<int> cache;

int rec(int num)
{
	if (num == 1) return 0;

	int& ret = cache[num];
	if (-1 != ret) return ret;

	int minValue = INF;
	if (num % 3 == 0) minValue = min(minValue, rec(num / 3) + 1);
	if (num % 2 == 0) minValue = min(minValue, rec(num / 2) + 1);
	if (num - 1 >= 1) minValue = min(minValue, rec(num - 1) + 1);

	ret = minValue;
	return minValue;
}

int main()
{
	int n;
	cin >> n;
	
	cache.assign(n + 1, -1);
	cout << rec(n) << endl;

	return 0;
}