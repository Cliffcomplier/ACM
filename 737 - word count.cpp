/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 45291
 * Submitted at:  2017-11-25 23:38:44
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    737
 * Problem Name:  word count
 */

#include<iostream>
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
vector<string>::iterator it;
void cancel(vector<string>&uniq);
int main() {
	string input;
	vector<string> ink;
	vector<string> uniq;
	int res[1000] = {0};
	while ((cin >> input) && (input != "1")) {
		ink.push_back(input);
	}
	sort(ink.begin(), ink.end());
	//the above code is correct. input an infinite text and sort them.
	uniq = ink;
	cancel(uniq);

	//start
	for(int a=0;a<uniq.size();a++)
		for (int b = 0; b < ink.size(); b++) {
			if (uniq[a] == ink[b]) {
				res[a]++;
			}
		}

	//end
	for (int j = 0; j < uniq.size(); j++) {
		cout << uniq[j] << " " << res[j] << endl;
	}
}

void cancel(vector<string>&uniq) {
	uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());
}

