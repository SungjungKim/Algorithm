#include <iostream>
using namespace std;

typedef struct _pos {
	int x;
	int y;
} Pos;

int board[102][102];


void init()
{
	front = 0;
	rear  = 0;

	for(int i = 0; i <= r+1; i++)
		for(int j = 0; j <= c+1; j++)
			board[i][j] = 101;
}


int isValid(int x, int y)
{
	// No
	if(board[x][y] < board[x-1][y] && board[x][y] < board[x+1][y] && board[x][y] < board[x][y-1] && board[x][y] < board[x][y-1])
		return 0;
	else // Yes
		return 1;
}


// get max number of up, down, left, right
int getMax(int x, int y)
{
	int max = board[x+1][y];

	if(board[x-1][y] > max)
		max = board[x-1][y];
	if(board[x][y-1] > max)
		max = board[x][y-1];
	if(board[x][y+1] > max)
		max = board[x][y+1];

	return max;
}


// return shortest path length;
int getLength(int x, int y, int length)
{
	int cur = board[x][y];
	int len = length;

	// loop while valid
	while(isValid(x, y)) {
		
	}

	return len;
}


// main process; go dfs
int process(int r, int c)
{
	int max_length = 0;

	for(int i = 1; i <= r; i++) {
		for(int j = 1; j <= c; j++) {
			if(getLength(i, j, 1) > max_length)
				max_length = getLength(i, j, 1);	
		
	return max_length;							
}


// main function
int main(void)
{
	int r, c;
	int k = 0;
	cin >> r >> c;

	init();

	for(int i = 1; i <= r; i++)  
		for(int j = 1; j <= c; j++) 
			cin >> board[i][j];

	cout << process(r, c) << endl;

	/*
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
	*/

	return 0;
}
