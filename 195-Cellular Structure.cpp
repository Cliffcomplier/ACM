#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main() {
	string input;
	string o;
	int n;
	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> input;

		int end = input.length()-1;
		if (input[end] == 'B') {
			if (input[end - 1] == 'A') {
				if (input.substr(0, end - 1) == o) {
					cout << "FULLY-GROWN" << endl;
					o = input;
				}
				else {
					cout << "MUTANT" << endl;
				}
				
			}
			else {
				
				cout << "MUTANT" << endl;
			}
		}
		else {
			if (input.length() == 1) {
				cout << "SIMPLE" << endl;
				o = input;
			}
			else {
				if (input[0] == 'B') {
					if (input.substr(1, end - 1) == o) {
						cout << "MUTAGENIC" << endl;
						o = input;
					}
					else {
						cout << "MUTANT" << endl;
					}
				}
				else {
					cout << "MUTANT" << endl;
				}
			}
		}
		
	}
}
