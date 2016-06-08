#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	// i: 출력해야 할 별 수, j: 출력해야 할 공백 수
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