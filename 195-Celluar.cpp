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
		string output = " ";
		cin >> input;
		int len = input.length();

		if ((input[input.length() - 1] == 'A') && (input.length() == 1)) {

			cout << "SIMPLE" << endl;

		}
		else {
				while (o!=input) {
				o=input;
					if (input.substr(input.length() - 2, 2) == "AB") {
						input = input.substr(0, input.length() - 2);
						if (output == " ") {
							output = "FULLY-GROWN";
						}
					}
					else if ((input[0] == 'B') && (input[input.length() - 1] == 'A')) {
						input = input.substr(1, input.length() - 2);
						if (output == " ") {
							output = "MUTAGENIC";
						}

					}

				}
				if (input[0] == 'A') {
					cout << output << endl;
				}
				else {
					cout << "MUTANT" << endl;
				}
			}
		}
}


