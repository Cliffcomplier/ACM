/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 77693
 * Submitted at:  2019-02-15 07:14:49
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    438
 * Problem Name:  Party
 */

#include<iostream>
using namespace std;
int main(){
	int t=0;
	cin>>t;
	for(int i=0;i<t;i++){
		int N=0;
		cin>>N;
		if(N>2)
			cout<<N-2<<endl;
		else
			cout<<0<<endl; 
	}
}