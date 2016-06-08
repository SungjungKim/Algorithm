#include <iostream>
using namespace std;

const int m = 1000000000;

int main()
{
	int a, b;
	cin >> a >> b;

	cout << "0." << (a * m) / b << endl;

	return 0;
}