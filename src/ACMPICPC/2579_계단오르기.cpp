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

// step번 here 단계에서 연속으로 step번 밟았을 때 최대 점수
int rec(int here, int step)
{
	// 3번 연속 밟았거나 내려갈 곳이 없을 경우
	if (step >= 3 || here < 0) return 0;

	int &ret = cache[here][step];
	if (-1 != ret) return ret;

	int one = arr[here] + rec(here - 1, step + 1);	// 한 칸 내려갈 경우
	int two = arr[here] + rec(here - 2, 1);			// 두 칸 내려갈 경우
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

	// 마지막 계단은 무조건 밟아야 하므로 마지막 계단부터 출발
	cout << rec(n - 1, 1) << endl;

	return 0;
}