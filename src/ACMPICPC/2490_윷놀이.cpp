/*
0 1 0 1
1 1 1 0
0 0 1 1
*/
#include <iostream>
#include <string>
using namespace std;

int yoot[4][3];
string base = "EABCD";

int main()
{
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 4; ++j)
			cin >> yoot[j][i];

	int count_zero;
	for (int i = 0; i < 3; ++i) {
		count_zero = 0;
		for (int j = 0; j < 4; ++j) {
			if (!yoot[j][i]) count_zero++;
		}
		cout << base.at(count_zero) << endl;
	}


	return 0;
}