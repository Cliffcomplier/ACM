/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 46477
 * Submitted at:  2017-12-16 00:13:27
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    754
 * Problem Name:  Hotel Arrangement
 */


#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int a[10000005];
int n,c;
int maxxi = 0;

int ok(int dist)
{
	int left=c-1;
	int last=a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i]-last >= dist)
		{
			left--;
			last=a[i];
		}
		if(left==0)
			return 1;
	}
	return 0;
}

void deal()
{
	int left = 1;
	int right = 1000000005;
	int mid = 1;
	int match = 1;
	while(1)
	{
		mid = (left+right)/2;
		if(left>right)
			break;
		if(ok(mid))
		{
			left=mid+1;
			if(mid>match)
				match=mid;
		}
		else
		{
			right=mid-1;
		}
	}
	printf("%d\n",match);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		maxxi=0;
		scanf("%d%d",&n, &c);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]>maxxi)
				maxxi=a[i];
		}
		sort(a, a+n);
		deal();
	}
}