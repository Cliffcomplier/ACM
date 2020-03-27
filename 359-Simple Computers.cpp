#include<iostream>
#include<string>
#include <stdio.h>
#include <string.h>
using namespace std;

int memory[32][8];

string input;
int nm = 0;
int accu = 0;
int pc = 0;
void co() {
	int terminate = 0;
	pc = 0;
	while (terminate != 1) {
		accu = accu & 255;
		pc = pc & 31;

		nm = pc;
		if (memory[nm][0] == 0) {

			if (memory[nm][1] == 0) {

				if (memory[nm][2] == 0) {

					//STA
					pc++;
					int x_s = memory[nm][7] + 2 * memory[nm][6] + 4 * memory[nm][5] + 8 * memory[nm][4] + 16 * memory[nm][3];
					x_s = x_s & 31;
					int temp = accu;
					for (int i = 7; i >= 0; i--) {
						if (accu != 0) {
							memory[x_s][i] = accu % 2;
							accu = accu / 2;
						}
						else
							memory[x_s][i] = 0;
					}
					accu = temp;


				}

				else {

					//LDA
					pc++;
					int x_l = memory[nm][7] + 2 * memory[nm][6] + 4 * memory[nm][5] + 8 * memory[nm][4] + 16 * memory[nm][3];
					x_l = x_l & 31;
					accu = memory[x_l][7] + 2 * memory[x_l][6] + 4 * memory[x_l][5] + 8 * memory[x_l][4] + 16 * memory[x_l][3] + 32 * memory[x_l][2] + 64 * memory[x_l][1] + 128 * memory[x_l][0];

				}

			}

			else {

				if (memory[nm][2] == 0) {

					//BEQ
					pc++;
					if (accu == 0)

						pc = memory[nm][7] + 2 * memory[nm][6] + 4 * memory[nm][5] + 8 * memory[nm][4] + 16 * memory[nm][3];

				}

				else {
					pc++;
					//NOP

				}

			}

		}

		else {

			if (memory[nm][1] == 0) {

				if (memory[nm][2] == 0) {
					pc++;
					//DEC

					accu -= 1;

				}

				else {
					pc++;
					//INC

					accu += 1;

				}

			}

			else {

				if (memory[nm][2] == 0) {
					pc++;
					//JMP

					pc = memory[nm][7] + 2 * memory[nm][6] + 4 * memory[nm][5] + 8 * memory[nm][4] + 16 * memory[nm][3];

				}

				else {
					pc++;
					//HLT

					terminate = 1;

				}

			}

		}


	}
	int output[8];
	int out = accu;

	for (int j = 7; j >= 0; j--) {
		if (out != 0) {
			output[j] = out % 2;
			out = out / 2;
		}
		else {
			output[j] = 0;
		}
	}

	for (int p = 0; p < 8; p++)

		cout << output[p];
	cout << endl;
}
int main() {
	nm = 0;
	while (getline(cin, input)) {

		for (int i = 0; i < 8; i++) {
			if (input[i] == '0')
				memory[nm][i] = 0;
			else if (input[i] == '1')
				memory[nm][i] = 1;
		}

		nm++;
		if (nm == 32) {
			nm = 0;
			//memset(memory, 0, sizeof memory);
			accu = 0;
			pc = 0;
			co();
			nm = 0;
			memset(memory, 0, sizeof memory);
		}


	}

}
