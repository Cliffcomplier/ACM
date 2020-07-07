/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 47115
 * Submitted at:  2017-12-17 16:30:09
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    78
 * Problem Name:  Largest Subsequence
 */

#include<iostream>
#include<string>
using namespace std;

char*max(char*seq, char*st);

char a;
int main() {
	char sequence[100];
	int N;
	cin >> N;
	for (int j = 0; j < N; j++) {
		cin >> sequence;
		char*ss = sequence;
		ss = max(sequence, ss);
		while (*ss != '\0')
			ss = max(sequence, ss + 1);
		cout << "\n";

	}
}
char*max(char*seq, char*st) {
	char*Max = st;//st=seq
	int i = 0;
	while (*(st + i) != '\0') {
		if (*Max < *(st + i))
			Max = st + i;
		i++;
	}
	if(*Max!='\0')
	cout << *Max;




	return Max;
}