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

	// start: ���������� ���۵� ���� ����
	// end: ���������� ���� ���� ����
	// maxValue: �ִ� ����(end - start)
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

		if (end < current) {	// ��������
			end = current;
		}
		else {	// ��������
			if (maxValue < end - start)
				maxValue = end - start;
			start = end = current;
		}

		i++;
	}

	cout << maxValue << endl;

	return 0;
}