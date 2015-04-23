/*
	Problem: 23_knight
	Name : Sungjung Kim
*/

#include <iostream>
using namespace std;

#define MAX_SIZE 1001

typedef struct _pos {
	int x;
	int y;
}Pos;


int board[MAX_SIZE][MAX_SIZE] = { 0, };
Pos direction[8] = { { 1, -2 }, { 2, -1 }, { 2, 1 }, { 1, 2 }, { -1, 2 }, { -2, 1 }, { -2, -1 }, { -1, -2 } };


// Valid: return true
bool isValid(Pos pos)
{
	if (pos.x < 1 || pos.x > MAX_SIZE - 1)
		return false;
	else if (pos.y < 1 || pos.y > MAX_SIZE - 1)
		return false;
	else if (board[pos.x][pos.y])
		return false;
	else
		return true;
}


int knightTour(Pos startPos, Pos endPos) 
{
	Pos nextPos = startPos;
	Pos curPos = nextPos;
	board[curPos.x][curPos.y] = 1;				// MARK Start Position

	while (!board[endPos.x][endPos.y]) {		// End Position�� ��ŷ�� ������ �ݺ�
		for (int i = 1; i < 1001; i++) {		// for row
			for (int j = 1; j < 1001; j++) {	// for col
				curPos.x = i;					// Set Current Position
				curPos.y = j;

				if (board[curPos.x][curPos.y]) {					// ���� �湮�� ������ ��ŷ���� ��� ���� �ܰ� ����
					for (int dir = 0; dir < 8; dir++) {				// for dir
						nextPos.x = curPos.x + direction[dir].x;	// �̵��� ������ x ��ǥ ����
						nextPos.y = curPos.y + direction[dir].y;	// �̵��� ������ y ��ǥ ����

						if (isValid(nextPos))												// �̵��� ��ǥ�� ��ȿ�� ���
							board[nextPos.x][nextPos.y] = board[curPos.x][curPos.y] + 1;	// �̵��� ��ǥ�� ��ŷ
					}
				}
			}
		}
	}

	return board[endPos.x][endPos.y] - 1;
}


int main(void)
{
	Pos startPos, endPos;
	cin >> startPos.x >> startPos.y;
	cin >> endPos.x >> endPos.y;

	cout << knightTour(startPos, endPos) << endl;

	return 0;
}