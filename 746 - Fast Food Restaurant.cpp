/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 46039
 * Submitted at:  2017-12-12 10:10:16
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    746
 * Problem Name:  Fast Food Restaurant
 */

#include<stdio.h>
#include<string.h>

struct Node
{
	int from,to;
};

Node a[100005];
int n;
int froma=0;
int toa=0;
int waitn=0;

int max(int i, int j)
{
	return i>j ? i:j;
}

void input()
{
	memset(a,0,sizeof(a));
	froma=0;
	toa=0;
	waitn=0;
	for(int i=0;i<n;i++)
	{
		int begin, last, l;
		scanf("%d%d%d",&begin, &last, &l);
		while(1)
		{
			if(froma==toa)
				break;
			if(begin>=a[froma].to)
			{
				froma++;
			}
			else
			{
				break;
			}
		}
		if(froma==toa)
		{
			a[toa].from=begin;
			a[toa].to=begin+last;
			toa++;
		}
		else if(toa-froma<=l)
		{
			a[toa].from=max(a[toa-1].to, begin);
			a[toa].to=a[toa].from+last;
			toa++;
		}
		else if(toa-froma>l && i==n-1)
		{
			printf("-1\n");
			return;
		}
	}
	printf("%d\n",a[toa-1].from);
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		input();
	}
}

答复

转发