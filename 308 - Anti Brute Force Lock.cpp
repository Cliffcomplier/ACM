/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 80414
 * Submitted at:  2019-03-16 19:51:56
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    308
 * Problem Name:  Anti Brute Force Lock
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

const int maxe = 1000000;
const int maxn = 1010;

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

	return x.w < y.w;

}
int roll(int x,int y) {
	int k1[4];
	int k2[4];
	memset(k1,0,sizeof k1);
	memset(k2, 0, sizeof k2);
	int d = 1000;
	for (int i = 0; i < 4; i++) {
		k1[i]=x/d;
		x = x % d;
		d = d / 10;
	}
	d = 1000;
	int r = 0;
	for (int i = 0; i < 4; i++) {
		k2[i] = y / d;
		y = y % d;
		d = d / 10;
		if (k1[i] > k2[i]) {
			int rr = k1[i] - k2[i];
			if (rr < 5)
				rr = rr;
			else
				rr = 10 - rr;
			r += rr;
		}
		else {
			int rr=k2[i] - k1[i];
			if (rr < 5)
				rr = rr;
			else
				rr = 10 - rr;
			r += rr;
		}
	}
	
	return r;
}
int kruskal(int m,int n) {
	sort(H, H+m, cmp);
	int sum=0;
	int add_e = 0;
	for (int i = 0; i < m; i++) {
		if (root(H[i].u) != root(H[i].v)) {
			par[root(H[i].u)] = root(H[i].v);
			add_e += 1;
			sum += H[i].w;

		}
		if (add_e == n - 1) {

			return sum;
		}
	}
}
int main() {
	int T = 0;
	scanf("%d",&T);
	for (int i = 1; i <= T; i++) {
		memset(H,0,sizeof H);
		//Step1: Build the graph
		int nk = 0;
		int key[maxn];
		scanf("%d",&nk);
		int nofe = 0;
		for (int i = 0; i < nk; i++) {
			scanf("%d",&key[i]);
			for (int j = i-1; j >=0; j--) {
				H[nofe].u = i;
				H[nofe].v = j;
				H[nofe].w = roll(key[i],key[j]);

				nofe++;
				
			}
		}
		//Step 1: End
		//Step 2: Build the mst(compute steps)
		memset(par,0,sizeof par);
		for (int g = 0; g < nk; g++) {
			par[g] = g;
		}
		int min = 0x7ffffff;
		for (int q = 0; q < nk; q++) {
			if (min > roll(0000, key[q])) {
				min = roll(0000, key[q]);
			}
		}
		cout << min + kruskal(nofe, nk) << endl;

		//Step 2: End
	}

}