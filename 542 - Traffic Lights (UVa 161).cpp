


/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 85282
 * Submitted at:  2019-05-05 13:00:02
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    542
 * Problem Name:  Traffic Lights (UVa 161)
 */

#include <iostream>
#include <cstdio>
#include<algorithm>
#include <sstream>
#define Max 120
#define fail 18000
using namespace std;

//23: 25 5 20 r y g
int main() {
	while (1) {
		bool T;
		int A[Max], N = 0, time[Max] = {};
		int B[Max];
		while (scanf("%d", &A[N]) == 1) {
			
			if (A[N] == 0)
				break;
			B[N] = A[N];
			N++;
		}
		if (A[0] == 0)
			return 0; // OUT
		
		sort(B, B + N);
		
		int min;
		for ( min = B[0]; min <= fail; min++) {
			T = true;
			for (int i = 0; i < N; i++) {
				while (time[i] + A[i] - 5 <= min) {
					time[i] += 2 * A[i];
				}
				bool danger = ( min < time[i] + A[i] - 5&& time[i] <= min);
				if (!danger) {
					min = time[i] - 1;
					T = false;
					break;
				}
			}
			if (T)
				break;
		}
		if (min > fail)
			printf("Signals fail to synchronise in 5 hours\n");
		else
			printf("%02d:%02d:%02d\n", min / 3600, min % 3600 / 60, min % 60);
	}
	return 0;
}

答复