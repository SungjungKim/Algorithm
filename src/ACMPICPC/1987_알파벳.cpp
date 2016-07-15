#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int DIR[4][2] = {
    -1, 0,
    0, -1,
    0, 1,
    1, 0};
struct Position {
    int x, y;
};
vector<vector<char> > board;
vector<int> letters;

bool canGo(Position position) {
    if (position.x >= 0 && position.x < board.size() && position.y >= 0 && position.y < board[0].size())
        return true;
    return false;
}

int tour(Position position, int currentValue) {
    int maxValue = currentValue;
    letters[board[position.x][position.y] - 65] = 1;

    for (int i = 0; i < 4; ++i) {
        Position nextPosition;
        nextPosition.x = position.x + DIR[i][0];
        nextPosition.y = position.y + DIR[i][1];
        if (canGo(nextPosition) && letters[board[nextPosition.x][nextPosition.y] - 65] == 0) {
            letters[board[nextPosition.x][nextPosition.y] - 65] = 1;
            maxValue = max(maxValue, tour(nextPosition, currentValue + 1));
            letters[board[nextPosition.x][nextPosition.y] - 65] = 0;
        }
    }

    return maxValue;
}

// for the test
void print() {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
	int R, C;
    scanf("%d %d", &R, &C);
    board.assign(R, vector<char> (C, '\0'));
    letters.assign(26, 0);

    string line;
    for (int i = 0; i < board.size(); ++i) {
        cin >> line;
        for (int j = 0; j < line.length(); ++j)
            board[i][j] = line[j];
    }

    //print();
    Position startPosition;
    startPosition.x = 0; startPosition.y = 0;
    printf("%d\n", tour(startPosition, 1));

    return 0;
}
