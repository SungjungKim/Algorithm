/*
봉우리가 여러개인 산 모양을 출력한다. 산 모양은 그림과 같고 좌우 대칭이다.


입력
입력은 20 이하의 자연수이다.

출력
출력 예의 형식으로 출력한다.

입출력 예
입력
1

출력
1

입력
2

출력
121

입력
3

출력
1213121

입력
4

출력
121312141213121

입력
5

출력
1213121412131215121312141213121
*/
#include <iostream>
using namespace std;

void process(int height) {
	if (height == 1) {
		cout << height;
		return;
	}

	process(height - 1);
	cout << height;
	process(height - 1);
}


int main(void) {
	int height;
	cin >> height;

	process(height);
}