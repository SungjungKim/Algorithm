/*
*	2����
*
*	Kookmin University
*	Computer Science Department
*	20103310 Sungjung Kim
*
*/

/*
�����̴� 2������ ������ ������ ���Ͽ� 10������ �Է��ϸ� 2������ ��µǵ��� �ϴ� ���α׷��� ������� �Ѵ�. 
�����̸� ��������.

Input
���� testcase �� N�� �Է¹޴´�.
���Ŀ� N��ŭ ��ȯ�ϰ��� �ϴ� 10������ ���� �Է��Ѵ�.
(10������ 1000������ �ڿ����� �����Ѵ�.)

Output
�Է¹��� ���� 2������ ��ȯ�Ͽ� ���ʴ�� ����Ѵ�.
(�߿�! testcase �������� #testcase��ȣ�� ��� �� ���� ���)
*/

/*

VCPP, GPP���� ���

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

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		/*

		�˰����� ���� �κ�

		*/

		int num_dec;
		cin >> num_dec;

		printBin(num_dec);

		cout << endl;
	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}