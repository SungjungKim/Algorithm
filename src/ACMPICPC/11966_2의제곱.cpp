#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	// 2��������: AND ������ ����� 0�� ���
	cout << ((n & (n - 1)) ? 0 : 1) << endl;

	return 0;
}