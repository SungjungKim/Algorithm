/*
5
20 10 35 30 7
*/
#include <iostream>
using namespace std;

const int MINNUM = -987654321, MAXNUM = 987654321;;

int main()
{
	int n, temp, maxValue = MINNUM, minValue = MAXNUM;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		if (temp > maxValue) maxValue = temp;
		if (temp < minValue) minValue = temp;
	}
	cout << minValue << " " << maxValue << endl;

	return 0;
}