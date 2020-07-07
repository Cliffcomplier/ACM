/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 79629
 * Submitted at:  2019-03-04 00:42:17
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    165
 * Problem Name:  Frogger (UVa 534) (Precision)
 */

#include <stdio.h>

#include <string.h>

#include <string>

#include <cmath>

#include <algorithm>

#include <math.h>

#include <iostream>

#include <cstdio>

#include <cstring>

using namespace std;



const int maxe = 40010;

const int maxn = 210;

struct edge {

	int u;

	int v;

	double w;

	edge(int u = 0, int v = 0, double w = 0x7ffffff) :u(u), v(v), w(w) {}





};

edge H[maxe];

int par[maxn];

int root(int x) {

	return x == par[x] ? x : par[x] = root(par[x]);

}//

bool cmp(const edge&x,const  edge&y) {

	return x.w < y.w;

}

double kruskal(int from, int to, int nofe) {

	sort(H, H + nofe, cmp);


	for (int i = 0; i < nofe; i++) {

		if (root(H[i].u) != root(H[i].v))

			par[root(H[i].u)] = root(H[i].v);

		if (root(from) == root(to))

			return H[i].w;

	}

}

double dist(int x1, int x2, int y1, int y2) { return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)); }

int main() {

	int T = -1;

	int x[maxn];

	int y[maxn];
	int S = 1;
	while (scanf("%d", &T) && T != 0) {

		int nofe = 0;
		
		memset(par, 0, sizeof par);

		for (int i = 0; i < T; i++) {

			scanf("%d %d", &x[i], &y[i]);

			par[i] = i;

			for (int j = 0; j < i; j++) {

				H[nofe].u = i;

				H[nofe].v = j;

				H[nofe].w = dist(x[i], x[j], y[i], y[j]);

				nofe++;

			}

		}

		printf("Scenario #%d\n", S);
		printf("Frog Distance = %.3f\n", kruskal(0, 1, nofe));
		printf("\n");
		S++;
	}

}

答复

转发
