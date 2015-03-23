/*
 *	11�� ��� ������
 *
 *	Kookmin University
 *	Computer Science Department
 *	20103310 Sungjung Kim
 *
 */

/*
���ڸ� �� ���� ���ϴ� �����̴� ���� 11�� ����� �ͼ����� �ʾҴ�. 
�̸� ��Ÿ���� ���� �ָ��� �����̿��� ������ �ְ��� 11�� ������� �Ǵ����ִ� ���α׷��� ������ֱ�� �Ͽ���. �ٰ��� �ָ��� ��������.

Input
���� testcase�� �� N�� �Է��Ѵ�.
�� ���� 300�� ������ �ڿ����� N����ŭ ���ʴ�� �־�����.

Output
�Է����� �־��� ���� 11�� ����̸� yes, �׷��� ������ no�� ����Ѵ�.
(�߿�! testcase �������� #testcase��ȣ�� ��� �� ���� ���)

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

VCPP, GPP���� ���

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

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		/*

		�˰����� ���� �κ�

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

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}