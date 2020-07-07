/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 77690
 * Submitted at:  2019-02-15 06:36:44
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    192
 * Problem Name:  Not so Mobile (UVa 839)
 */

#include<iostream>
#include<cstdlib>
#include <cstring>
#include <cstdio>


using namespace std;


int my_abs(int a)
{
	int i = a >> 31;
	return ((a ^ i) - i);
}
int ob(int wl = 0, int dl = 0, int wr = 0, int dr = 0) {
	int l = 0, r = 0;
	if (wl != 0 && wr != 0) {
		if (wr*dr == wl * dl) {
			return wl + wr;
		}
		else {
			return 0;
		}
	}
	else {

			if (wl == 0) {
				int a = 0, b = 0, c = 0, d = 0;
				scanf("%d %d %d %d", &a, &b, &c, &d);
				wl = ob(a, b, c, d);
			}

		

			if (wr == 0) {
				int a = 0, b = 0, c = 0, d = 0;
				scanf("%d %d %d %d", &a, &b, &c, &d);
				wr = ob(a, b, c, d);
			}
		
		if (wr!=0&&wl!=0&&wr*dr == wl * dl) {
			return wl + wr;
		}
		else {
			return 0;
		}
	}
	

}

int main() {
	bool first=true;
	int n = 0;
	scanf("%d", &n);
	char sp;
	scanf("%c", &sp);
	for (int i = 0; i < n; i++) {
		scanf("%c", &sp);
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if (ob(a, b, c, d) == 0) {
			if (first) {
				first = false;
			}
			else {
				cout << endl;
			}
			cout << "NO\n";
		}
		else {
			if (first) {
				first = false;
			}
			else {
				cout << endl;
			}
			cout << "YES\n";
		}


	}
	return 0;
}
