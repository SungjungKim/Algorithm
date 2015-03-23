/*
*	���� ã��
*
*	Kookmin University
*	Computer Science Department
*	20103310 Sungjung Kim
*
*/

/*

�����̴� �ɽ��Ҷ����� �ٴڿ� ���ڰ� ���ִ� 5*5 ũ���� ���ڸ� �׸� ��, Ư���� ��Ģ�� ���� ���ڹ��� ����� ���. 
Ư���� ��Ģ�� �� ������ �����¿쿡 �ִ� ���Һ��� ������ ���Ұ��� ������ �ش���ġ�� ���ڰ� �ִٰ� �Ǵ��ϴ� ���̴�. 
���� ��� �Ʒ��� ���� ���ڹ��� ��������� �Ķ��� �� �ȿ� �ִ� �κ��� ���ڰ� �ִٰ� �Ǵ��ϴ� ���̴�.

������ �����̴� �� ���ڹ� ��Ģ�� �ʹ� ��ƴٰ� �����Ͽ� ���ڰ� �ִ� �κп� * ǥ�ø� �ϰ��� �Ѵ�. 
�����̸� ���� ���� �ִ� ���� ǥ�ø� �ϵ��� ����.

Input
��ü testcase ��  N�� �Է� �޴´�. �� ���� ����� ���� �־�����. 5*5 ����� ����ϸ� �� ���� 0~9������ ���� �־�����.

Output
��ü�� �ٽ� ����ϵ�, ���ںκ��� ��� *�� ǥ���Ͽ� ����Ѵ�.
(�߿�! testcase �������� #testcase��ȣ �� ��� �� ���� ���)

Input sample
1
3 4 1 4 9
2 9 4 5 8
9 0 8 2 1
7 0 2 8 4
2 7 2 1 4

Output sample
#testcase1
3 4 * 4 9
* 9 4 5 8
9 0 8 2 *
7 0 2 8 4
* 7 2 * 4

*/

/*

VCPP, GPP���� ���

*/

#include <iostream>
using namespace std;

int board[7][7] = { 0, };
int solution[7][7] = { 0, };

/*
Initialize 7*7 board.

board
10 10 10 10 10 10 10
10  .  .  .  .  . 10
10  .  .  .  .  . 10
10  .  .  .  .  . 10
10  .  .  .  .  . 10
10  .  .  .  .  . 10
10 10 10 10 10 10 10

solution
0 0 0 0 0 0 0
0 . . . . . 0
0 . . . . . 0
0 . . . . . 0
0 . . . . . 0
0 . . . . . 0
0 0 0 0 0 0 0
*/
void initBoard() {
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			board[i][j] = 10;

	for (int i = 1; i < 6; i++) {
		for (int j = 1; j < 6; j++) {
			cin >> board[i][j];
			solution[i][j] = board[i][j];
		}
	}
}



/*
process : Find mine.

				board[i-1][j]
					>
board[i][j-1]	> board[i][j] <	board[i][j+1]
					<
				board[i+1][j]
*/
void findMine() {
	for (int i = 1; i < 6; i++)
		for (int j = 1; j < 6; j++)
			if (board[i][j] < board[i][j - 1] && board[i][j] < board[i][j + 1] && board[i][j] < board[i - 1][j] && board[i][j] < board[i + 1][j])
				solution[i][j] = 11;	// check
}


/*
print 5*5 solution board.
: 11 -> '*'
*/
void printBoard() {
	for (int i = 1; i < 6; i++) {
		for (int j = 1; j < 6; j++) {
			if (solution[i][j] == 11)
				cout << "* ";
			else
				cout << solution[i][j] << " ";
		}
		cout << endl;
	}
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

		initBoard();	// init 7*7 board.
		findMine();		// process.
		printBoard();	// print 5*5 solution board.
	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}