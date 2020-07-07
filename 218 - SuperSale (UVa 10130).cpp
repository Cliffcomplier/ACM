


/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 80396
 * Submitted at:  2019-03-16 02:38:15
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    218
 * Problem Name:  SuperSale (UVa 10130)
 */

#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<algorithm>
using namespace std;


int price[1010];
int weight[1010];
int person[110];


int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N;

		memset(price, 0, sizeof price);
		memset(weight, 0, sizeof weight);
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &price[i], &weight[i]);
		}

		memset(person, 0, sizeof person);
		int G;
		scanf("%d", &G);
		for (int j = 0; j < G; j++) {
			scanf("%d", &person[j]);
		}
		int mp[40];
		memset(mp,0,sizeof mp);
		int i;
		for (int j = 0; j < N; j++) {

			for (i = 30; i >= weight[j];i--) {
				
					mp[i] = max(mp[i - weight[j]] + price[j], mp[i]);
				
				
			}
	
		}
		int value = 0;
		for (int k = 0; k < G; k++) {
			value += mp[person[k]];
		}
		cout << value << endl;
	}

}