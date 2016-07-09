/*
5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6
*/
#include <iostream>
#include <vector>
#include <pair>
using namespace std;

vector<pair<int, int> > matrix;

void init(int edge) {
    for (int i = 0; i < edge; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        make_pair(from, to) = weight;
    }
}

void print() {
    for (int i = 0; i < matrix.size(); ++i) {
        cout << matrix[i].first << " " << matrix[i].second << endl;
    }
}

int main() {
	int vertex, edge, start;
	cin >> vertex >> edge >> start;

    init(edge);
    print();
    
	return 0;
}
