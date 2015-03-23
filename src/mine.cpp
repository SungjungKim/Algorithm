/*
*	지뢰 찾기
*
*	Kookmin University
*	Computer Science Department
*	20103310 Sungjung Kim
*
*/

/*

성중이는 심심할때마다 바닥에 숫자가 들어가있는 5*5 크기의 격자를 그린 뒤, 특별한 규칙을 가진 지뢰밭을 만들어 논다. 
특별한 규칙은 한 원소의 상하좌우에 있는 원소보다 현재의 원소값이 작을때 해당위치는 지뢰가 있다고 판단하는 것이다. 
예를 들어 아래와 같이 지뢰밭이 만들어지면 파란색 셀 안에 있는 부분은 지뢰가 있다고 판단하는 것이다.

하지만 성중이는 이 지뢰밭 규칙이 너무 어렵다고 생각하여 지뢰가 있는 부분에 * 표시를 하고자 한다. 
성중이를 도와 지뢰 있는 곳에 표시를 하도록 하자.

Input
전체 testcase 수  N을 입력 받는다. 그 다음 행렬의 값이 주어진다. 5*5 행렬을 사용하며 각 수는 0~9사이의 수가 주어진다.

Output
전체를 다시 출력하되, 지뢰부분의 경우 *로 표시하여 출력한다.
(중요! testcase 개수마다 #testcase번호 를 출력 후 정답 출력)

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

VCPP, GPP에서 사용

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

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		/*

		알고리즘이 들어가는 부분

		*/

		initBoard();	// init 7*7 board.
		findMine();		// process.
		printBoard();	// print 5*5 solution board.
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}