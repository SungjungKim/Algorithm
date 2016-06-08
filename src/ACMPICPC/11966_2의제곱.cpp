#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	// 2의제곱수: AND 연산의 결과가 0일 경우
	cout << ((n & (n - 1)) ? 0 : 1) << endl;

	return 0;
}