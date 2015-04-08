/**************************************************
*
*   seat
*
*   SAMSUNG SOFTWARE MEMBERSHIP
*   25-1 Kim Sungjung
*
**************************************************/

#include <iostream>
using namespace std;

// Number of seat : 1~40
int seat[42] = { 0, };
int fix[42] = { 0, };


void initSeat(int num_seat, int num_fix) {
	int k;

	for (int i = 0; i < 42; i++)
		fix[i] = 0;

	for (k = 1; k <= num_fix; k++)
		cin >> fix[k];

	fix[k] = num_seat + 1;
}


// fibonacci
int fib(int num) {
	if (num <= 3)
		return num;

	return fib(num - 1) + fib(num - 2);
}



int process(int num_fix) {
	int temp;
	int result = 1;

	for (int i = 1; i <= num_fix + 1; i++) {
		if (fix[i] - fix[i-1] - 1 == 0)
			continue;

		temp = fib(fix[i] - fix[i - 1] - 1);
		result *= temp;
	}

	return result;
}


int main(void) {
	int num_seat, num_fix;
	cin >> num_seat >> num_fix;

	initSeat(num_seat, num_fix);
	cout << process(num_fix) << endl;
}
