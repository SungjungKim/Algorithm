/*
*	2진수
*
*	Kookmin University
*	Computer Science Department
*	20103310 Sungjung Kim
*
*/

/*
주찬이는 2진수의 개념을 익히기 위하여 10진수를 입력하면 2진수가 출력되도록 하는 프로그램을 만들고자 한다. 
주찬이를 도와주자.

Input
먼저 testcase 값 N을 입력받는다.
이후에 N만큼 변환하고자 하는 10진수의 수를 입력한다.
(10진수는 1000이하의 자연수로 제한한다.)

Output
입력받은 수를 2진수로 변환하여 차례대로 출력한다.
(중요! testcase 개수마다 #testcase번호를 출력 후 정답 출력)
*/

/*

VCPP, GPP에서 사용

*/

#include <iostream>
using namespace std;

void printBin(int dec) {
	if (dec == 0 || dec == 1) {
		cout << dec;
		return;
	}

	printBin(dec / 2);
	cout << dec % 2;
}

int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		/*

		알고리즘이 들어가는 부분

		*/

		int num_dec;
		cin >> num_dec;

		printBin(num_dec);

		cout << endl;
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}