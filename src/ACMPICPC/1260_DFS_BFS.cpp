#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int startPosition;
vector<vector<int> > board;
vector<bool> visited;

void DFS(int position) {
   visited[position] = true;
   printf("%d ", position);
   for (int i = 1; i < board.size(); ++i) {
       if (!visited[i] && board[position][i]) {
           DFS(i);
       }
   }
}

void BFS() {
    queue<int> q;
    q.push(startPosition);
    visited[startPosition] = true;

    while (!q.empty()) {
        int currentPosition = q.front();
        q.pop();
        printf("%d ", currentPosition);
        for (int i = 1; i < board.size(); ++i) {
            // 아직 방문하지 않았고 간선이 존재할 경우
            if (!visited[i] && board[currentPosition][i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d %d", &N, &M, &startPosition);
    board.assign(N + 1, vector<int>(N + 1, 0));

    int from, to;
    for (int i = 0; i < M; ++i) {
        scanf("%d %d", &from, &to);
        board[from][to] = board[to][from] = 1;
    }

    visited.assign(N + 1, false);
    DFS(startPosition);
    printf("\n");

    visited.assign(N + 1, false);
    BFS();
    printf("\n");

    return 0;
}
