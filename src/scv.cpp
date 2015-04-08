/**************************************************
*
*   scv
*
*   SAMSUNG SOFTWARE MEMBERSHIP
*   25-1 Kim Sungjung
*
**************************************************/

#include <iostream>
using namespace std;

#define MAX(a,b) (a > b ? a : b)

int board[101][101] = { 0, };

void initBoard(int n) {
	// padding
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}
}

void printBoard(int n) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}



void process(int n) {
	int temp = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			temp = MAX(board[i][j - 1], board[i - 1][j]);

			if (board[i][j] == 0)
				board[i][j] = temp;
			else	// board[i][j] = 1
				board[i][j] = temp + 1;
		}
	}
}


int main(){
	int n;
	cin >> n;	// 세로, 가로

	initBoard(n);
	process(n);
	//printBoard(n);

	cout << board[n][n] << endl;
}