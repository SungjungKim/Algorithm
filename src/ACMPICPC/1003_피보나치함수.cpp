#include <iostream>
using namespace std;

int arr[40][2] = { 0, };

void init() {
	for (int i = 0; i < 40; i++)
		for (int j = 0; j < 2; j++)
			arr[i][j] = 0;
}
/*
f(n) = 
(n = 0) 0
(n = 1) 1
(n > 1) f(n-2) + f(n-1)
*/
void fib(int n)
{
	arr[0][0] = 1;
	arr[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		arr[i][0] = arr[i - 2][0] + arr[i - 1][0];
		arr[i][1] = arr[i - 2][1] + arr[i - 1][1];
	}
}

int main()
{
	int num_test, n;
	cin >> num_test;
	for (int i = 0; i < num_test; i++) {
		cin >> n;
		init();
		if (n == 0) {
			cout << 1 << " " << 0 << endl;
		}
		else if (n == 1) {
			cout << 0 << " " << 1 << endl;
		}
		else {
			fib(n);
			cout << arr[n][0] << " " << arr[n][1] << endl;
		}
	}
	return 0;
}