#include <iostream>
#include <string>
using namespace std;

int n;
string command;
int stack[100001];
int top = -1;

void push(int num)
{
	stack[++top] = num;
}

// pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 
// 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int pop()
{
	if (top == -1) return -1;
	return stack[top--];
}

// size: 스택에 들어있는 정수의 개수를 출력한다.
int size()
{
	return top + 1;
}

// empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
int empty()
{
	if (top == -1) return 1;
	else return 0;
}

// top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int _top()
{
	if (top == -1) return -1;
	return stack[top];
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i){
		int number;
		cin >> command;

		if (command == "push") {
			cin >> number;
			push(number);
		}
		else if (command == "top") {
			cout << _top() << endl;
		}
		else if (command == "pop") {
			cout << pop() << endl;
		}
		else if (command == "size") {
			cout<< size() << endl;
		}
		else if (command == "empty") {
			cout << empty() << endl;
		}
	}

	return 0;
}