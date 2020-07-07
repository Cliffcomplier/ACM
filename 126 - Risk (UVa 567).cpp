/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 77691
 * Submitted at:  2019-02-15 06:41:12
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    126
 * Problem Name:  Risk (UVa 567)
 */

#include<iostream>
#include<stdio.h>
#include<iostream>
#include<stdio.h>
#include<cstring>

using namespace std;

typedef struct enode {
	int data;
	enode*next;
}edge;

edge*H[21];
int visit[21];

int add_edge() {
	int flag;
	std::memset(H, 0, sizeof(H));
	for (int i = 1; i < 20; i++) {
		int t = 0;
		if (cin >> t) {
			flag = 1;
		}
		else {
			flag = 0;
		}
		for (int j = 0; j < t; j++) {
			int s = 0;
			cin >> s;
			edge*p = new edge;
			p->data = s;
			p->next = H[i];
			H[i] = p; //The last next =0;
			edge*q = new edge;
			q->data = i;
			q->next = H[s];
			H[s] = q; //The last next =0;

		}
	}
	return flag;
}

int cou = 0;
int mgt(int*Que, int e) {
	int move = 0;
	int q[20];

	memset(q, 0, sizeof q);

	int i = 0;

	while (Que[move]) {
		if (Que[move] == e) {
			return cou;
		}

		for (enode*p = H[Que[move]]; p; p = p->next) {
			if (!visit[p->data]) {
				q[i++] = p->data;
				visit[p->data] = 1;

			}
		}



		move++;
	}

	mgt(q, e);
	cou++;
}
int len(int s, int e) {
	int Q[20];
	int co = 0;
	memset(Q, 0, sizeof Q);
	Q[0] = s;




	co = mgt(Q, e);

	return co;
}
int main() {
	int time = 1;
	while (add_edge()) {
		int sp[101];
		int ep[101];
		int rp[101];
		
			int n = 0;
			cin >> n;
			for (int i = 0; i < n; i++) {
				int x = 0, y = 0;
				cou = 0;
				scanf("%d %d", &x, &y);
				sp[i] = x;
				ep[i] = y;
				int Q[19];
				Q[0] = x;
				memset(visit, 0, sizeof(visit));
				visit[x] = 1;
				rp[i] = len(x, y);

			}
			printf("Test Set #%d\n",time++);
			for (int l = 0; l < n; l++)
				printf("%2d to %2d: %d\n",sp[l],ep[l],rp[l]);
			printf("\n");
		
		

}
	
}