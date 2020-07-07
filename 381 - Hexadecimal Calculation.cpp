/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 77229
 * Submitted at:  2019-02-02 12:32:53
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    381
 * Problem Name:  Hexadecimal Calculation
 */

#include<iostream>
#include<stdio.h>
#include<stack>
#include <string.h>
#include <string>

using namespace std;


int htod(char x) {
	int a;
	if ((x >= '0') && (x <= '9'))
		a = x - '0';
	else
		a = x - 'A' + 10;
	return a;

}
char dh(int a) { //Missing things
	char x;
	if ((a <= 9) && (a >= 0))
		x = a + '0';
	else
		x = a - 10 + 'A';
	return x;
}
string dtoh(int a) {
	string x;
	int max = 0;
	int sub;
	int m = 1;
	int denom;
	while (m <= a) {
		m *= 16;
		max++;
	}
	denom = m;
	denom = denom / 16;
	if (denom != 0) {

		sub = a;
		x = dh(sub / denom); //Possible wrong
		sub = sub % denom;
		for (int i = 0; i < max - 1; i++) {
			denom = denom / 16;

			x = x + dh(sub / denom); //Possible wrong
			sub = sub % denom;
		}
	}
	else {
		x = dh(a);
	}
	return x;
}
int main() {

	char lin = ' ';
	bool flag = true;
	int n = 0;
	char I[100] = { 'o' };
	int q = 0; //I[]
	int g = 0; //Input
	string store;
	while (cin >> store) {
		std::stack<char> s;
		char input[100];

		for (int i = 0; i < store.length(); i++) {
			lin = store[i];
			if ((lin >= '0') && (lin <= '9') || (lin >= 'A') && (lin <= 'F') || (lin == ' ')) {
				input[g] = lin;
				g++;
			}
			else if (lin == '(') {
				s.push(lin);
			}
			else if (lin == '+') {
				if ((s.empty()) || (s.top() == '(')) {
					s.push(lin);
				}
				else {
					while ((!s.empty()) && ((s.top() == '+') || (s.top() == '*'))) {
						input[g] = s.top();
						g++;
						s.pop();

					}
					s.push(lin);
				}

			}
			else if (lin == '*') {
				if (s.empty()) {
					s.push(lin);
				}
				else if ((s.top() == '+') || (s.top() == '(')) {
					s.push(lin);
				}
				else if (s.top() == '*') {
					input[g] = s.top();
					g++;
					s.pop();
					s.push(lin);
				}
			}
			else if (lin == ')') {

				while ((!s.empty()) && (s.top() != '(')) {
					input[g] = s.top();

					g++;
					s.pop();
				}
				if (s.top() == '(')
					s.pop();
			}


		}
		while (!s.empty()) {
			input[g] = s.top();
			s.pop();
			g++;
		}

		int a = 0;
		int b = 0;
		int c = 0;
		char op = 'n';
		std::stack<int> stack;
		for (int i = 0; i < g; i++) {
			if ((input[i] >= '0') && (input[i] <= '9') || (input[i] >= 'A') && (input[i] <= 'F')) {
				stack.push(htod(input[i]));
			}
			else {

				a = stack.top();
				stack.pop();
				b = stack.top();
				stack.pop();
				if (input[i] == '+')
					c = a + b;
				else if (input[i] == '*')
					c = a * b;
				stack.push(c);
				c = 10000000;
			}
		}
		g = 0;
		
		std::cout << dtoh(stack.top()) << endl;
	
	}


	return 0;


}