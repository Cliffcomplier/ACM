/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 77103
 * Submitted at:  2019-01-31 20:40:28
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    27
 * Problem Name:  Gems in the maze
 */

#include<iostream>

using namespace std;

int Travel(int a, int b, int c, int n) {
	int gem, tun;

	int result = 0;
	int start = 0, end = n - 1;

	while (start != end) {
		int z[300] = { 0 };
		int temp = start;
		int r = 0;
		while (z[temp] != 1) {
			
			z[temp] = 1;
			tun = (a*(temp*temp) + b*temp + c) % n;
			temp = tun;
			r++;
		}

		

		if (r < result)
			result = result;
		else
			result = r;
		start++;
	}
	return result;
}
int main() {
	int a, b, c, n;
	int times;
	int fr[100] = { 0 };
	cin >> times;
	for (int i = 0;i < times;i++) {
		cin >> a >> b >> c >> n;

		fr[i] = Travel(a, b, c, n);

	}
	for (int i = 0;i < times;i++) {


		cout << fr[i] << endl;

	}
	
}
