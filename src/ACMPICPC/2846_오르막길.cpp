/*
8
12 20 1 3 4 4 11 1
*/
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	// start: 오르막길이 시작될 때의 높이
	// end: 오르막길이 끝날 때의 높이
	// maxValue: 최대 높이(end - start)
	// i: loop iterator
	int start, end, maxValue = 0, i = 1;
	cin >> start;
	end = start;
	
	while (true) {
		if (i == n) {
			if (maxValue < end - start)
				maxValue = end - start;
			break;
		}

		int current;
		cin >> current;

		if (end < current) {	// 오르막길
			end = current;
		}
		else {	// 내리막길
			if (maxValue < end - start)
				maxValue = end - start;
			start = end = current;
		}

		i++;
	}

	cout << maxValue << endl;

	return 0;
}