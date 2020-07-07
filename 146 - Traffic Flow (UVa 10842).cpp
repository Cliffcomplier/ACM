/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 80412
 * Submitted at:  2019-03-16 17:41:18
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    146
 * Problem Name:  Traffic Flow (UVa 10842)
 */

#include <stdio.h>
#include <string.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <cstdio>


using namespace std;

const int maxe = 10010;
const int maxn = 110;

struct edge {
	int u;
	int v;
	int w;
	edge(int u = 0, int v = 0, int w = 0x7ffffff) :u(u), v(v), w(w) {}

};
edge H[maxe];
int par[maxn];
int root(int x) {

	return x == par[x] ? x : par[x] = root(par[x]);

}//
bool cmp(const edge&x, const  edge&y) {

	return x.w > y.w;

}
int kruskal(int m,int n) {
	sort(H, H+m, cmp);

	int add_e = 0;
	for (int i = 0; i < m; i++) {
		if (root(H[i].u) != root(H[i].v)) {
			par[root(H[i].u)] = root(H[i].v);
			add_e += 1;
		}
		if (add_e == n - 1) {

			return H[i].w;
		}
	}
}
int main() {
	int T = 0;
	scanf("%d",&T);
	for (int i = 1; i <= T; i++) {
		int n, m;
		memset(H,0,sizeof H);
		scanf("%d %d", &n, &m);
		for (int j = 0; j < m; j++) {
			int u, v, c;
			scanf("%d %d %d",&u,&v,&c);
			H[j].u = u;
			H[j].v = v;
			H[j].w = c;
		}
		for (int t = 0; t < n; t++) {
			par[t] = t;
		}
		printf("Case #%d: %d\n",i,kruskal(m,n));
	}

}
