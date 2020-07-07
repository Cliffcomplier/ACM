/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 46126
 * Submitted at:  2017-12-13 23:47:52
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    751
 * Problem Name:  Reverse Polish Notation
 */

#include<iostream>
#include<sstream>
#include<stack>
using namespace std;

int RPN(string&str) {
	stack<int>rpn;
	int op, a, b, result;

	for (int i = 0; i < str.length(); i++) {

		if (str[i] >= '0'&&str[i] <= '9') {
			op = str[i] + 0 - '0';
			rpn.push(op);

		}
		else if (str[i] == '+') {
			a = rpn.top();
			rpn.pop();
			b = rpn.top();
			rpn.pop();
			rpn.push((a + b));
			//cout << a << '+' << b << '=' << (a + b) << endl;

		}
		else if (str[i] == '-') {
			a = rpn.top();
			rpn.pop();
			b = rpn.top();
			rpn.pop();
			rpn.push((b - a));
			//cout << a << '-' << b << '=' << (a - b) << endl;
		}
		else if (str[i] == '*') {
			a = rpn.top();
			rpn.pop();
			b = rpn.top();
			rpn.pop();
			rpn.push((a * b));
			//cout << a << '*' << b << '=' << (a * b) << endl;
		}
		else if (str[i] == '/') {
			a = rpn.top();
			rpn.pop();
			b = rpn.top();
			rpn.pop();
			rpn.push((b / a));
			//cout << a << '/' << b << '=' << (a / b) << endl;
		}
	}
	result = rpn.top();
	rpn.pop();

	return result;
}
int main() {
	string str;
	while (getline(cin, str)) {
		cout << RPN(str) << endl;
	}

}