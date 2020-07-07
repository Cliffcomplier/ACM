/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 80368
 * Submitted at:  2019-03-15 18:13:27
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    217
 * Problem Name:  Coin Change (UVa 674)
 */

//217 Coin Change
#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<string>
using namespace std;

int coin[] = { 1,5,10,25,50 };

int main() {
	int way[7490];
	int amt;
	for (int i = 0; i < 7490; i++) {
		way[i] = 1;
	}
	for (int j = 1; j <= 4;j++) {
		for (int k = 0; k < 7490; k++) {
			if (k >= coin[j]) {
				way[k] = way[k] + way[k - coin[j]];
			}
		}
	}
	while (cin>>amt) {
		cout << way[amt] << endl;
	}
}