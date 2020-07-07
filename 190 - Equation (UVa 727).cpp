/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 77221
 * Submitted at:  2019-02-02 04:33:14
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    190
 * Problem Name:  Equation (UVa 727)
 */

#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;

int main()
{


	char l;
	bool flag=true;
	char sp = ' ';
	//Length of x
	int n = 0; // Times of programming run.
	scanf("%d", &n);
	scanf("%c", &sp);
	scanf("%c", &sp);
	for (int i = 0; i < n; i++) {
		char x[100];
		int h = 0; //Counter for x[50]
		std::stack<char> s;
		while ((scanf("%c", &l) != EOF) && (l != '\n')) {

			
			if (((int)l >= 48) && ((int)l <= 57)) {
				while (((int)l >= 48) && ((int)l <= 57)) {
					x[h] = l;
					h++;
					scanf("%c", &l);
				}

			}
			else {
				if ((l == '+') || (l == '-')) {
					if ((s.empty()) || (s.top() == '(')) {
						s.push(l);
					}
					else {
						while ((!s.empty())&&((s.top() == '+') || (s.top() == '-') || (s.top() == '*')||(s.top()=='/'))) {
							x[h] = s.top();
							h++;
							s.pop();
							
					}
						s.push(l);
					}

				}
				else if ((l == '*') || (l == '/')) {
					if (s.empty()) {
						s.push(l);
					}
					else {
						if (s.top() == '(') {
							s.push(l);
						}
						else if ((s.top() == '+') || (s.top() == '-')) {
							s.push(l);
						}
						else if ((s.top() == '*') || (s.top() == '/')) {
							x[h] = s.top();
							h++;
							s.pop();
							s.push(l);
						}
					}
				}
				else if (l == ')') {
					if (!s.empty()) {
						while (s.top() != '(') {
							x[h] = s.top();
							s.pop();
							h++;
						}
					}
					s.pop();
				}
				else if (l == '(') {
					s.push(l);
				}
				scanf("%c", &sp);// Cancel out cl
			}


		}
		while (!s.empty()) {
			x[h] = s.top();
			h++;
			s.pop();
		}
		if(flag){
			for (int j = 0; j < h; j++){
				cout << x[j];
			}
			flag=false;
			cout<<endl;
		}else{
			cout<<endl;
			for (int j = 0; j < h; j++){
				cout << x[j];
				flag=false;
			}
			cout<<endl;
		}
			

	}
	
	return 0;

}