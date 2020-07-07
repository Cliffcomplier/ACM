/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 46029
 * Submitted at:  2017-12-11 23:27:47
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    372
 * Problem Name:  Jumping Mario
 */

#include<iostream>

using namespace std;
void count(int&high,int&low);
int main() {
	int T,h=0,l=0;
	cin >> T;
	for (int k = 0; k < T; k++) {
	count(h, l);
		cout << "Case "<<k+1 << ": "<<h << " " << l<< "\n";
		h = 0, l = 0;
	}
}
void count(int&high, int&low) {
	int N;
	int a, b;
	cin >> N >> a;
	for (int i = 0; i < N-1; i++) {
		cin >> b;
		if (a > b)
			low++;
		else if (a < b)
			high++;
		a = b;
	}

}