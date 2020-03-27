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
