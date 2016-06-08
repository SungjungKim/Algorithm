#include <iostream>
#include <vector>
#include <string>
using namespace std;

string line;
vector<vector<string> > board;

int main()
{
	int count = 0;
	board.assign(11, vector<string>(11, " "));
	for (int i = 1; i <= 8; ++i) {
		cin >> line;
		for (int j = 1; j <= 8; ++j) {
			board[i][j] = line.at(j - 1);
			if ((i + j) % 2 == 0 && board[i][j] == "F")
				count++;
		}
	}

	cout << count << endl;

	return 0;
}