#include <iostream>
using namespace std;

int sosu(int num)
{
	for (int i = 2; i <= num; i++) {
		if (num != i && num % i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	int n, num, count = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		if (num == 1) continue;
		if (num == 2) count++;
		else if (sosu(num) == 1) count++;
	}

	cout << count << endl;

	return 0;
}