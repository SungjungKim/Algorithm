#include <iostream>
using namespace std;

int main()
{
	int n, i, j;
	cin >> n;

	// i: ����ؾ� �� ���� ��, j: ����ؾ� �� �� ��
	i = n - 1, j = 1;
	while (true) {
		if (i == -1) break;

		for (int k = 0; k < i; ++k)
			cout << " ";
		for (int k = 0; k < j; ++k)
			cout << "*";
		cout << endl;

		i--; j++;
	}

	return 0;
}