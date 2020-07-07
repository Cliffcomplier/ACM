/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 77396
 * Submitted at:  2019-02-08 00:34:44
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    134
 * Problem Name:  Dominos 2 (UVa 11518)
 */

#include<iostream>
#include<cstdlib>
#include <cstring>
#include <cstdio>
#include<list>
#include<stack>

using namespace std;




int main() {
	int Q[10010];
	int times = 0;
	char sp;

	while (cin >> times) {
		for (int i = 0; i < times; i++) {
			list<int> H[10010];
			int n = 0, m = 0, l = 0;

			scanf("%d %d %d", &n, &m, &l);
			scanf("%c", &sp);
			//cout << n << m << l << endl;
			for (int j = 0; j < m; j++) {
				int x = 0, y = 0;
				scanf("%d %d", &x, &y);
				scanf("%c", &sp);
				H[x].push_back(y);
			}
			int count = 0;
			int visit[10010];
			memset(visit, 0, sizeof(visit));
			for (int k = 0; k < l; k++) {
				int z = 0;
				cin >> z;
				
				int result = 0;
			
				memset(Q, 0,sizeof(Q));
				Q[0] = z;
				visit[z] = 1;
				result += 1;
				int move = 0, save = 1;
				while (move < save) {
					int now = Q[move++];
					list<int>::iterator iter;
					for (iter = H[now].begin(); iter != H[now].end(); iter++) {
						if (!visit[*iter]) {
							visit[*iter] = 1;
							result += 1;
							Q[save++] = *iter;
						}
					}
				}
			

			}
			for (int i = 1; i <= n; ++i)

				count += visit[i];
			cout << count << endl;


		}
	}

}