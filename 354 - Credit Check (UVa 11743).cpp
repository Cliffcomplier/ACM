#include<iostream>
using namespace std;

int main() {
	int cre[15] = { 0 };
	int d = 0;
	int N = 0;
	int s[1000];
	int po = 0;
	cin >> N;
	int verify = 0;
	for (int i = 0;i < N;i++) {
		int verify1 = 0;
		int verify2 = 0;
		// Input
		for (int j = 0;j < 4;j++) {

				cin >> d;
				verify1 += (2 * (d / 1000)) % 10 + (2 * (d / 1000)) / 10 + (2 * ((d % 100) / 10)) % 10 + (2 * ((d % 100) / 10)) / 10;

				verify2 += ( ((d / 100) % 10)) % 10 + ( ((d / 100) % 10)) / 10 + ( (((d % 1000) % 100) % 10)) % 10 + ( (((d % 1000) % 100) % 10)) / 10;

			
		}

		// Step 3
		verify = verify1 + verify2;

		//step 3

		if (verify % 10 == 0)
			s[po] = 1;
		else
			s[po] = -1;
		po++;

	}
	for (int y = 0;y < N;y++) {
		if (s[y] == -1)
			cout << "Invalid" << endl;
		else
			cout << "Valid" << endl;
	}

}
