/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 79632
 * Submitted at:  2019-03-04 02:00:45
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    172
 * Problem Name:  Rough Roads (UVa 10356)
 */

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;


typedef struct node {
	int n;
	int d;
	node*next;
}Graph;
Graph*H[500];
int main() {
	int T = 1;
	int n = 0;
	int r = 0;
	while ((scanf("%d %d", &n, &r) != EOF)) {

		//Step 1: Build the tree
		memset(H, 0, sizeof H);
		for (int i = 0; i < r; i++) {
			int j1 = 0, j2 = 0;
			int len = 0;
			scanf("%d %d %d", &j1, &j2, &len);
			Graph*p = new Graph;
			p->d = len;
			p->n = j2;
			p->next = H[j1];
			H[j1] = p;
			Graph*q = new Graph;
			q->d = len;
			q->n = j1;
			q->next = H[j2];
			H[j2] = q;
		}
		//Step 1: End

		//Step 2: Reform the tree
		Graph*R[500];
		memset(R, 0, sizeof R);
		for (int j = 0; j < n; j++) {
			for (Graph*s1 = H[j]; s1; s1 = s1->next) {
				for (Graph*s2 = H[s1->n]; s2; s2 = s2->next) {
					if (s2->n != j) {
						int Len = s1->d + s2->d;
						int exist = 0;
						for (Graph*v = R[j]; v; v = v->next) {
							if (v->n == s2->n) {
								v->d = v->d > Len ? v->d : Len;
								Graph*unknq;
								int I = 0;
								for (unknq = R[s2->n]; unknq->n != j; unknq = unknq->next) {
									I++;
								}
								unknq->d = Len;


								exist = 1;
							}
						}
						if (exist == 0) {
							Graph*newp = new Graph;
							newp->d = Len;
							newp->n = s2->n;
							newp->next = R[j];
							R[j] = newp;
							Graph*newq = new Graph;
							newq->d = Len;
							newq->n = j;
							newq->next = R[s2->n];
							R[s2->n] = newq;
						}
					}
				}
			}
		}
		//Step 2: End

		//Step 3: Use Djikstra algo to find the shortest path
		int dist[500];
		memset(dist, 1000000, sizeof dist);
		//int visit[500];
		int Vn[500];
		memset(Vn, 0, sizeof Vn);
		//memset(visit,0,sizeof visit);
		
		Vn[0] = 1;
		for (Graph*p = R[0]; p; p = p->next) {
			dist[p->n] = p->d;
		}
		
		bool sol = true;
		while (!Vn[n - 1]) {
			int min = 1000000;
			int ava = -1;
			for (int i = 0; i < n; i++) {
				if (min > dist[i]&& !Vn[i]) {
					min = dist[i];
					ava = i;
				}
			}
			if (ava == -1) {
				sol = false;
				break;
			}
			Vn[ava] = 1;
	
			for (Graph*q = R[ava]; q; q = q->next) {
				if (!Vn[q->n]) {
					if (dist[q->n] > dist[ava] + q->d) {
						dist[q->n] = dist[ava] + q->d;
					}
				}
			}


		}
		//Step 3: End
		printf("Set #%d\n", T);
		T++;
		if (sol)
			printf("%d\n", dist[n - 1]);
		else
			cout << "?" << endl;

	}
}

答复

转发