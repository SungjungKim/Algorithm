/*
 *	11의 배수 판정법
 *
 *	Kookmin University
 *	Computer Science Department
 *	20103310 Sungjung Kim
 *
 */

/*
숫자를 잘 세지 못하는 준혁이는 아직 11의 배수에 익숙하지 않았다. 
이를 안타깝게 여긴 주리는 준혁이에게 도움을 주고자 11의 배수인지 판단해주는 프로그램을 만들어주기로 하였다. 다같이 주리를 도와주자.

Input
먼저 testcase의 수 N을 입력한다.
그 다음 300자 이하의 자연수가 N개만큼 차례대로 주어진다.

Output
입력으로 주어진 수가 11의 배수이면 yes, 그렇지 않으면 no를 출력한다.
(중요! testcase 개수마다 #testcase번호를 출력 후 정답 출력)

Input sample
3
11
121121
1000

Output sample
#testcase1
yes
#testcase2
yes
#testcase3
no

*/

/*

VCPP, GPP에서 사용

*/

#include <iostream>
using namespace std;


// return length of char
int getLength(char *ch) {
	int length = 0;

	while (*ch++ != NULL)
		length++;

	return length;
}

int sum1(char *ch, int length) {
	int sum = 0;
	int i = length - 1;

	while (i >= 0) {
		sum += ch[i] - 48;
		i -= 2;
	}	

	return sum;
}

int sum2(char *ch, int length) {
	int sum = 0;
	int i = length - 2;

	while (i >= 0) {
		sum += ch[i] - 48;
		i -= 2;
	}

	return sum;
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

		char num[301];
		int length;
		int sum;

		cin >> num;

		length = getLength(num);

		if ((sum1(num, length) - sum2(num, length)) % 11)
			cout << "no" << endl;
		else
			cout << "yes" << endl;


	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}