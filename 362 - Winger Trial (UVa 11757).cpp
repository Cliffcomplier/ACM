/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 82820
 * Submitted at:  2019-04-23 18:57:11
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    362
 * Problem Name:  Winger Trial (UVa 11757)
 */

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<queue>
#include<vector>

using namespace std;

const int MAXN = 210;    //Catory
const int INF = 0x3f3f3f3f; //Check it
struct Edge {
	int from, to, cap, flow;
	Edge(int u, int v, int c, int f) :from(u), to(v), cap(c), flow(f) {}
};

struct EK {
	int n, m;
	vector<Edge> edges;
	vector<int> G[MAXN];
	int a[MAXN];
	int p[MAXN];

	void init(int n) {
		for (int i = 0; i < n; i++) G[i].clear();
		edges.clear();

	}

	void AddEdge(int from, int to, int cap) {
		edges.push_back(Edge(from, to, cap, 0));
		edges.push_back(Edge(to, from, 0, 0));
		int m = edges.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}

	int MaxFlow(int s, int t) {
		int flow = 0;
		for (;;) {
			memset(a, 0, sizeof(a));
			queue<int> Q;
			Q.push(s);
			a[s] = INF;
			while (!Q.empty()) {
				int x = Q.front();
				Q.pop();
				for (int i = 0; i < G[x].size(); i++) {
					Edge& e = edges[G[x][i]];
					if (!a[e.to] && e.cap > e.flow) {
						p[e.to] = G[x][i];
						a[e.to] = min(a[x], e.cap - e.flow);
						Q.push(e.to);
					}
				}
				if (a[t]) break;
			}
			if (!a[t]) break;
			for (int u = t; u != s; u = edges[p[u]].from) {
				edges[p[u]].flow += a[t];
				edges[p[u] ^ 1].flow -= a[t];
			}
			flow += a[t];
		}
		return flow;
	}
};

int main() {
	int L, W, N, d;
	const int maxR = 110;
	int T = 0;
	while (scanf("%d %d %d %d", &L, &W, &N, &d) && (L+W+N+d!=0)) {
		int x[maxR];
		int y[maxR];
		EK ek;
		int s = 0;
		int t = 2 * N + 2+1;
		memset(x, 0, sizeof x);
		memset(y, 0, sizeof y);
		for (int i = 1; i <=N; i++) {
			scanf("%d %d", &x[i], &y[i]);
		}
		for (int j = 1; j <=N; j++) {
			ek.AddEdge(j , j  + N, 1);
			if (y[j] <= d)
				ek.AddEdge(j+N, t, 1);// S: 0
			if (y[j] + d >= W)
				ek.AddEdge(0,j, 1);//T: 1
			for (int k = j + 1; k <=N; k++) {
				if ((x[j] - x[k])*(x[j] - x[k]) + (y[j] - y[k])*(y[j] - y[k]) <= 4 * d*d) {
					ek.AddEdge(j +N,k, 1);
					ek.AddEdge(k  +N, j , 1);
				}
			}

		}
		printf("Case %d: %d\n", ++T, ek.MaxFlow(s, t));

	}
}

答复

转发