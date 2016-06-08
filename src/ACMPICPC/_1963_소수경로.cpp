#include <iostream>
#include <queue>
#include <string>
using namespace std;

int a, b;
queue<int> q;
int arr[9999] = { 0, };

int sosu(int num) {
	for (int i = 2; i <= num; i++)
		arr[i] = i;

	for (int i = 2; i <= num; i++) {
		if (i == num && arr[i] == 0)	// 이미 체크된 수의 배수는 확인하지 않는다.
			return 0;
		for (int j = i + i; j <= num; j += i)	// i를 제외한 i의 배수들은 0으로 체크
			arr[j] = 0;
	}
	return 1;
}

int sol(int end)
{
	int count = 0;
	while (!q.empty()) {
		int num = q.front();
		q.pop();

		if (num == end) return count;
		count++;

		for (int i = num; i < 9999; ++i) {
			if (sosu(i) == 0) continue;

		}
	}

	return -1;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)  {
		cin >> a >> b;
		q.push(a);

		int result = sol(b);
		if (result == -1) cout << "Impossible" << endl;
		else cout << result << endl;
	}

	return 0;
}