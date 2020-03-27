
#include <iostream>

#include <cstdlib>

#include <cstring>

#include <cstdio>



using namespace std;



int visit[10010];



//link_list_start

typedef struct enode

{

	int   point;

	enode*next;

}edge;

edge*H[10010];

edge E[10010];

int  edge_count;



void inital()

{

	edge_count = 0;

	memset(H, 0, sizeof(H));

}



void add_edge(int a, int b)

{

	E[edge_count].point = b;

	E[edge_count].next = H[a];

	H[a] = &E[edge_count++];

}

//link_list_over



int  Q[10010];

void bfs(int s, int n)

{

	Q[0] = s;

	visit[s] = 1;

	int move = 0, save = 1;

	while (move < save) {

		int now = Q[move++];

		for (edge* p = H[now]; p; p = p->next)

			if (!visit[p->point]) {

				visit[p->point] = 1;

				Q[save++] = p->point;

			}

	}

}



int main()

{

	int T, n, m, l, a, b, s;

	while (~scanf("%d", &T))

		for (int t = 1; t <= T; ++t) {

			scanf("%d%d%d", &n, &m, &l);

			inital();

			for (int i = 0; i < m; ++i) {

				scanf("%d%d", &a, &b);

				add_edge(a, b);

			}



			memset(visit, 0, sizeof(visit));

			for (int i = 0; i < l; ++i) {

				scanf("%d", &s);

				bfs(s, n);

			}



			int count = 0;

			for (int i = 1; i <= n; ++i)

				count += visit[i];

			printf("%d\n", count);

		}

	return 0;

}
