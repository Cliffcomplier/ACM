/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 80360
 * Submitted at:  2019-03-15 14:32:57
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    174
 * Problem Name:  Minimum Transport Cost (UVa 523)
 */

#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<string>
using namespace std;

const int maxn = 1000;
const int Max = 1000000;
typedef struct node {
	int n;
	int d;
	node*next;
}city;
city*H[maxn];
int parent[maxn];
int tax[maxn];
int read(string l1, int*a) {


	string seg = "";
	int N = 0;

	for (int i = 0; i < l1.length(); i++) {
		if (l1[i] != ' ') {
			seg += l1[i];
		}
		else {
			a[N] = stoi(seg);
			seg = "";
			N++;
		}
	}
	a[N] = stoi(seg);
	return N + 1;
}
int djk(int beg, int end, int N) {
	beg = beg - 1;
	end = end - 1;
	memset(parent, 0, sizeof parent);
	int dist[maxn];
	int Vn[maxn];
	memset(dist, Max, sizeof dist);
	memset(Vn, 0, sizeof Vn);
	Vn[beg] = 1;
	dist[beg] = 0;
	int ava = beg;
	int pre;
	for (city*p = H[beg]; p; p = p->next) {

		if (p->n != end) {
			if (dist[p->n] > dist[beg] + p->d + tax[p->n]) {
				dist[p->n] = dist[beg] + p->d + tax[p->n];
				parent[p->n + 1] = beg + 1;
			}
		}
		else {
			if (dist[p->n] > dist[beg] + p->d) {
				dist[p->n] = dist[beg] + p->d;
				parent[p->n + 1] = beg + 1;
			}
		}

	}

	while (!Vn[end]) {
		//Step1: Find the nearest node: ava.
		int min = Max;

		for (int i = 0; i < N; i++) {
			if ((!Vn[i]) && (min > dist[i])) {
				min = dist[i];
				ava = i;
			}
		}
		//Step2: Update the distance
		for (city*p = H[ava]; p; p = p->next) {
			if (p->n != end) {
				if (dist[p->n] > dist[ava] + p->d + tax[p->n]) {
					dist[p->n] = dist[ava] + p->d + tax[p->n];
					parent[p->n + 1] = ava + 1;
				}
			}
			else {
				if (dist[p->n] > dist[ava] + p->d) {
					dist[p->n] = dist[ava] + p->d;
					parent[p->n + 1] = ava + 1;
				}
			}
		}
		Vn[ava] = 1;



	}

	return dist[end];

}
int main() {
	int a[maxn];
	memset(a, 0, sizeof a);
	string s;
	int M = 0,cas=0;
	scanf("%d\n\n", &M);
	for (int i = 0; i < M; i++) {
		getline(cin, s);
		int N = read(s, a);

		for (int k = 0; k < N; k++) {
			if (a[k] != -1) {
				city*tmp = new city;
				tmp->next = H[0];
				tmp->n = k;
				tmp->d = a[k];
				H[0] = tmp;
			}
		}
		memset(a, 0, sizeof a);
		for (int j = 0; j < N - 1; j++) {
			getline(cin, s);
			read(s, a);

			for (int k = 0; k < N; k++) {
				if (a[k] != -1) {
					city*tmp = new city;
					tmp->next = H[j + 1];
					tmp->n = k;
					tmp->d = a[k];
					H[j + 1] = tmp;
				}
			}
			memset(a, 0, sizeof a);
		}
		memset(tax, 0, sizeof tax);
		getline(cin, s);
		read(s, tax);
		getline(cin, s);
		
		while (s != "") {
			memset(a, 0, sizeof a);
			read(s, a);
			int Distance = djk(a[0], a[1], N);
			if (cas++)
				puts("");
			printf("From %d to %d :\n", a[0], a[1]);
			int path[maxn];
			memset(path, 0, sizeof path);
			int t = 0;
			printf("Path: %d", a[0]);
			for (int v = a[1]; v != a[0]; v = parent[v]) {
				path[t] = v;
				t++;
			}

			for (int i = t - 1; i >= 0; i--) {
				printf("-->%d", path[i]);
			}

			printf("\nTotal cost : %d\n", Distance);
		
			getline(cin, s);
		}

	}



}