#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	// i: ����ؾ� �� �� ��, j: ����ؾ� �� ���� ��
	int i = n, j = 0;
	while (true) {
		if (i == 0) break;

		for (int k = 0; k < j; ++k)
			cout << " ";
		for (int k = 0; k < i; ++k)
			cout << "*";
		cout << endl;

		i--; j++;
	}

	return 0;
}