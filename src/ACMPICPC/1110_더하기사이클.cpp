#include <iostream>
using namespace std;

int src[2] = { 0, };
int tmp[2] = { 0, };

int process() {
	int temp, count = 0;

	while (true) {
		if (src[0] == tmp[0] && src[1] == tmp[1] && count != 0) {
			break;
		}

		temp = tmp[0] + tmp[1];
		tmp[0] = tmp[1];
		tmp[1] = temp % 10;
		count++;
	}

	return count;
}

int main(void) {
	int data;
	cin >> data;

	// init
	src[0] = data / 10;
	src[1] = data % 10;

	tmp[0] = src[0];
	tmp[1] = src[1];
	
	// process
	cout << process() << endl;

	return 0;
}