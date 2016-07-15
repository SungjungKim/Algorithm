#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

const int DIR[4][2] = {
    -1, 0,
    0, -1,
    1, 0,
    0, 1};
struct Position {
    int x, y;
};
vector<vector<char> > board;
vector<vector<int> > visited;

bool canGo(Position position) {
    if (position.x >= 0 && position.x < board.size() && position.y >= 0 && position.y < board[0].size()) 
        if (visited[position.x][position.y] == 0)
            if (board[position.x][position.y] == 'L')
                return true;
    return false;
}

int search(Position startPosition) {
    visited.assign(board.size(), vector<int>(board[0].size(), 0));
    queue<Position> q;
    q.push(startPosition);
    int maxValue = 0;

   while (!q.empty()) {
       Position currentPosition = q.front();
       q.pop();
       for (int i = 0; i < 4; ++i) {
           Position nextPosition;
           nextPosition.x = currentPosition.x + DIR[i][0];
           nextPosition.y = currentPosition.y + DIR[i][1];
           if (canGo(nextPosition)) {
               maxValue = visited[nextPosition.x][nextPosition.y] = visited[currentPosition.x][currentPosition.y] + 1;
               q.push(nextPosition);
           }
       }
   }

   return maxValue;
}

int main() {
    int row, col;
    cin >> row >> col;
    board.assign(row, vector<char>(col, '\0'));

    string line;
    for (int i = 0; i < board.size(); ++i) {
        cin >> line;
        for (int j = 0; j < line.length(); ++j) {
            board[i][j] = line[j];
        }
    }

    Position startPosition;
    int maxValue = 0;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (board[i][j] == 'L') {
                startPosition.x = i; 
                startPosition.y = j;
                maxValue = max(maxValue, search(startPosition));
            }
        }
    }

    printf("%d\n", maxValue);

    return 0;
}
