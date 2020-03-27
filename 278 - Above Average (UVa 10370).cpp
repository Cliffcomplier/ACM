#include<iostream>

using namespace std;

int main() {
	int l = 0;
	cin >> l;
	for (int i = 0; i < l; i++) {
		double t = 0;
		double avg = 0;
		int score[999];
		double above = 0;
		cin >> t;
		for (int j = 0; j < t; j++) {
			cin >> score[j];
			avg += score[j];
		}
		avg = avg / t;
		for (int h = 0; h < t; h++) {
			if (score[h] > avg)
				above++;

		}
		above = 100 * above;
		printf("%.3lf%%\n", above / t);
	}
}
