/*
Finding Max (Divide & Conquer)

max([a1, a2, ... , an]) =	(n=1) : a1
							(n>1) : MAX(max([a1, ... , ak]), max([ak+1, ... , an]))
*/
#include <iostream>
using namespace std;

#define MAX_SIZE 100
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int recurMax(int a[], int left, int right) {
	int half;

	if (left == right)
		return a[left];
	else {
		half = (left + right) / 2;
		MAX(recurMax(a, left, half), recurMax(a, half + 1, right));
	}
}

void main(void) {
	int arr[MAX_SIZE] = { 5, 3, 9, 2, 4, 8, 1, 6, 0, 7 };
	cout << recurMax(arr, 0, 9) << endl;
}
