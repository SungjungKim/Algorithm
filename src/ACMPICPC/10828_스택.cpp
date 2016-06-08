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

// pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. 
// ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
int pop()
{
	if (top == -1) return -1;
	return stack[top--];
}

// size: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
int size()
{
	return top + 1;
}

// empty: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
int empty()
{
	if (top == -1) return 1;
	else return 0;
}

// top: ������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
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