/*
입력
2
VISIT http://blog.secmem.org/
BACK
BACK
VISIT http://www.samsung.co.kr
BACK
FORWARD
QUIT
VISIT https://www.secmem.org/member/login/
VISIT https://www.secmem.org/board/bo_notice_nation/
BACK
BACK
BACK
FORWARD
VISIT http://blog.secmem.org/
BACK
BACK
FORWARD
FORWARD
FORWARD
QUIT

출력
#testcase1
http://blog.secmem.org/
https://secmem.org/
Ignored
http://www.samsung.co.kr
https://secmem.org/
http://www.samsung.co.kr
#testcase2
https://www.secmem.org/member/login/
https://www.secmem.org/board/bo_notice_nation/
https://www.secmem.org/member/login/
https://secmem.org/
Ignored
https://www.secmem.org/member/login/
http://blog.secmem.org/
https://www.secmem.org/member/login/
https://secmem.org/
https://www.secmem.org/member/login/
http://blog.secmem.org/
Ignored
*/

#include <iostream>
#include <string>
using namespace std;

class Stack_Forward {
private:
	int top;
	string browser[100];

public:
	Stack_Forward() {
		top = -1;
	}
	void initStack();
	void push(string browser);
	string pop();
};

void Stack_Forward::initStack() {
	top = -1;
}

void Stack_Forward::push(string url) {
	if (top > 100) {
		cout << "Ignored" << endl;
		return;
	}

	browser[++top] = url;
}


string Stack_Forward::pop() {
	if (top == -1) {
		cout << "Ignored" << endl;
		return "";
	}

	return browser[top--];
}


class Stack_Backward {
private:
	int top;
	string browser[100];

public:
	Stack_Backward() {
		top = 1;
		browser[0] = "https://secmem.org/";
	}
	void initStack();
	void push(string browser);
	string pop();
};

void Stack_Backward::initStack() {
	top = 1;
}

void Stack_Backward::push(string url) {
	if (top > 100) {
		cout << "Ignored" << endl;
		return;
	}

	browser[++top] = url;
}


string Stack_Backward::pop() {
	if (top == -1) {
		return "Ignored";
	}

	return browser[top--];
}


int main(void) {

	//char function[5] = {"BACK", "FORWARD", "VISIT", "QUIT"};
	string str;
	string current_url;
	Stack_Forward stack_forward;
	Stack_Backward stack_backward;

	while (true) {
		cin >> str;
		//getline(cin, str);
		if (str == "QUIT")
			break;
		
		switch (str.at(0))
		{
		case 'V':
			cin >> str;		// url
			stack_backward.push(str);
			current_url = str;
			cout << current_url << endl;
			stack_forward.initStack();

			break;
		case 'B':
			stack_forward.push(current_url);
			current_url = stack_backward.pop();
			cout << current_url << endl;

			break;
		case 'F':
			stack_backward.push(current_url);
			current_url = stack_forward.pop();
			cout << current_url << endl;

			break;
		default:
			break;
		}
	}
}