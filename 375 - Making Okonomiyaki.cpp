/****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 83134
 * Submitted at:  2019-04-25 16:28:25
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    375
 * Problem Name:  Making Okonomiyaki
 */

#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<string.h>
#include<stdio.h>
using namespace std;
class node {
public:
	int cur[4];
	int step;
};
int cap[4];
bool vis[30][30][30][30];
int tim(int v) {
	queue<node> q;
	memset(vis, 0, sizeof vis);
	while (!q.empty()) {
		q.pop();
	}
	node a, b, c, p;
	memset(a.cur, 0, sizeof a.cur);
	a.step = 0;
	q.push(a);
	vis[a.cur[0]][a.cur[1]][a.cur[2]][a.cur[3]] = 1;
	while (!q.empty()) {
		p = q.front();
		q.pop();
		for (int j = 0; j < 4; j++) {
			if (p.cur[j] == 0) {
				b = p;
				b.cur[j] = cap[j];

				b.step++;
				if (b.cur[j] == v)
					return b.step;
				if (!vis[b.cur[0]][b.cur[1]][b.cur[2]][b.cur[3]]) {
					q.push(b);
					vis[b.cur[0]][b.cur[1]][b.cur[2]][b.cur[3]] = 1;
				}
			}
			else {
				b = p;
				b.cur[j] = 0;
				b.step++;
				if (b.cur[j] == v)
					return b.step;
				if (!vis[b.cur[0]][b.cur[1]][b.cur[2]][b.cur[3]]) {
					q.push(b);
					vis[b.cur[0]][b.cur[1]][b.cur[2]][b.cur[3]] = 1;
				}
			}
			if (p.cur[j]) {
				for (int k = 0; k < 4; k++) if (j != k) {
					if (p.cur[j] > cap[k] - p.cur[k]) {
						c = p;
						c.cur[j] = c.cur[j] - cap[k] + c.cur[k];
						c.cur[k] = cap[k];
						c.step++;
						if ((c.cur[j] == v) || (c.cur[k] == v))
							return c.step;
						if (!vis[c.cur[0]][c.cur[1]][c.cur[2]][c.cur[3]]) {
							q.push(c);
							vis[c.cur[0]][c.cur[1]][c.cur[2]][c.cur[3]] = 1;
						}

					}
					else {
						c = p;
						c.cur[k] = c.cur[k] + c.cur[j];
						c.cur[j] = 0;
						c.step++;
						if ((c.cur[j] == v) || (c.cur[k] == v))
							return c.step;
						if (!vis[c.cur[0]][c.cur[1]][c.cur[2]][c.cur[3]]) {
							q.push(c);
							vis[c.cur[0]][c.cur[1]][c.cur[2]][c.cur[3]] = 1;
						}
					}
				}

			}
		}

		
	}
	return -1;
}

int main() {
	//Start
	int T;
	memset(cap,0,sizeof cap);
	//Get cap;
	while (scanf("%d %d %d %d %d", &cap[0], &cap[1], &cap[2], &cap[3],&T)!=EOF) {
		if (max(max(cap[0], cap[1]), max(cap[2], cap[3])) <= T) {
			if (max(max(cap[0], cap[1]), max(cap[2], cap[3])) == T)
				printf("%d\n", 1);
			else
				printf("%d\n",-1);
		}
		else {
			printf("%d\n", tim(T));
		}

	}
	

}