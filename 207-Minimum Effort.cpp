/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 85271
 * Submitted at:  2019-05-05 10:55:05
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    207
 * Problem Name:  Minimum Effort
 */

#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<string.h>
#include<stdio.h>
#include<map>


using namespace std;
const int maxn = 220;
const int maxe = 48400;
const int Max = 1000000000;
const int INF = 1000000000;
map<string, int> ip;
vector<string> out;
typedef struct node {
	int n;
	int d;
	node*next;
}pla;
pla*H[maxn];
int par[maxn];
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
void Addedge(string s) {
	int a, b, c, cc;
	bool tag = 0;
	c = -1;
	cc = -1;
	int state = 0;
	string sub;
	sub.clear();
	bool match = false;
	for (int i = 0; i < s.size(); i++) {
		if (state == 0) {

			if (s[i] == ':') {
				a = ip[sub];
				sub.clear();
				state = 1;
			}
			if (state == 0) {
				sub += s[i];
			}
		}
		else if (state == 1) {
			int z = 0;
			sub += s[i];
			//TLE

			for (int d = 0; d < out.size() && !match; d++) {

				//cout << sub.size() << " " << out[d].size() << " " << sub[0] << " " << out[d][0] << endl;
				//bool key = (char)(sub[0]) - (char)(out[d][0]);
				bool sz = sub == out[d];

				match = sz;


			}//find place
			if (match) {
				b = ip[sub];
				sub.clear();
				state = 2;
				i += 1;
			}


		}
		else if (state == 2) {
			if (s[i] == ' ') {
				c = stoi(sub);

				tag = true;
				sub.clear();
				state == 3;
			}
			if (state == 2)
				sub += s[i];
		}
		else if (state == 3) {
			sub += s[i];
		}

	}
	if (!sub.empty()) {
		if (tag == 1)
			cc = stoi(sub);
		else
			c = stoi(sub);

	}

	//printf("%d %d %d %d\n",a,b,c,cc);
	pla*e = new pla;
	e->n = b;
	e->d = c;
	e->next = H[a];
	H[a] = e;
	//**********************Check**********************
	//printf("**********************Check**********************\n");
	//cout << out[a] << ":" << out[b] << " " <<c<< " \n";

	if (cc != -1) {
		pla*f = new pla;
		f->n = a;
		f->d = cc;
		f->next = H[b];
		H[b] = f;
		//printf("**********************Check**********************\n");
		//	cout << out[b] << ":" << out[a] << " " <<cc<< " \n";

	}

}
void initial() {
	ip.clear();
	memset(par, 0, sizeof par);
	memset(H, 0, sizeof H);
	out.clear();
}
int djk(int beg, int end, int N) {

	memset(par, 0, sizeof par);
	int dist[maxn];
	bool Vn[maxn];
	for (int i = 0; i < N; i++) {
		dist[i] = Max;
	}
	memset(Vn, 0, sizeof Vn);
	Vn[beg] = 1;
	dist[beg] = 0;
	int ava = beg;
	int pre;
	for (pla*p = H[beg]; p; p = p->next) {
		dist[p->n] = dist[beg] + p->d;
		par[p->n] = beg;

	}
	ava = -1;
	while (!Vn[end]) {
		//Step1: Find the nearest node: ava.
		int min = Max;

		for (int i = 0; i < N; i++) {
			if ((!Vn[i]) && (min > dist[i])) {
				min = dist[i];
				ava = i;
			}
		}

		Vn[ava] = 1;
		//Step2: Update the distance
		for (pla*p = H[ava]; p; p = p->next) {

			if (!Vn[p->n] && dist[p->n] > dist[ava] + p->d) {
				dist[p->n] = dist[ava] + p->d;
				par[p->n] = ava;

			}

		}

	}

	return dist[end];

}
void check(int N) {
	for (int i = 0; i < N; i++) {
		cout << out[i] << "->";
		for (pla*p = H[i]; p; p = p->next)
			cout << out[p->n] << "(" << p->d << ")" << "->";
		cout << endl;
	}
}
int main() {
	int N;
	string s;
	bool first = true;
	while (scanf("%d\n", &N) != EOF) {
		initial();
		for (int i = 0; i < N; i++) {
			getline(cin, s);
			ip.insert(pair<string, int>(s, i));
			out.push_back(s);
		}

		int P;
		scanf("%d\n", &P);
		for (int i = 0; i < P; i++) {
			getline(cin, s);
			Addedge(s);


			//cout << "Check " << i << endl;

		
		}
		//printf("*************Check*****************\n");
		//check(N);
		//map<string, int>::iterator it;
		//for (it = ip.begin(); it != ip.end();it++) {
		//	cout << it->first << " " << it->second <<" "<<out[it->second]<< endl;
		//}
		//system("pause");
		//printf("*************Check*****************\n");
		int path[2 * maxn];
		int s = ip["office"];
		int t = ip["hall"];
		//
		//printf("*************Check*****************\n");
		//check(N);
		int sp = djk(ip["office"], ip["hall"], N);
		//

		int z = 0;
		int l = 0;
		for (int i = t; i != s; i = par[i]) {
			path[z] = i;
			z++;
		}
		l = z;
		path[z] = s;
		z++;
		//
		int spb = djk(ip["hall"], ip["office"], N);
		//
		
			
	

		for (int i = s; i != t; i = par[i]) {
			path[z] = i;
			z++;
		}
		printf("%d\n", (sp + spb));
		for (int g = l; g >= 0; g--) {
			//	printf("%s -> ", out[path[g]]);
			cout << out[path[g]] << " -> ";
		}
		for (int g = z - 1; g > l + 1; g--) {
			//	printf("%s -> ", out[path[g]]);
			cout << out[path[g]] << " -> ";
		}
		//printf("%s\n", out[path[l + 1]]);
		cout << out[path[l + 1]] << "\n";
		printf("\n");

	}
}

答复

转发
