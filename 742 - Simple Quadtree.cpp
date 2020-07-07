/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 46019
 * Submitted at:  2017-12-11 17:41:47
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    742
 * Problem Name:  Simple Quadtree
 */

#include<stdio.h>
#include<string.h>

int k;
int n;
char a[1050][1050];
int sum=0;


void deal(int fromr, int fromc, int tor, int toc)
{
	for(int i=fromr;i<tor;i++)
	{
		for(int j=fromc;j<toc;j++)
		{
			if(a[i][j]!=a[fromr][fromc])
			{
				sum+=4;
				deal(fromr, fromc, (fromr+tor)/2, (fromc+toc)/2);
				deal((fromr+tor)/2, fromc, tor, (fromc+toc)/2);
				deal(fromr, (fromc+toc)/2, (fromr+tor)/2, toc);
				deal((fromr+tor)/2, (fromc+toc)/2, tor, toc);
				return;
			}
		}
	}
}

int main()
{
	while(scanf("%d",&k)!=EOF)
	{
		memset(a,0,sizeof(a));
		sum = 1;
		n=(1<<k);
		for(int i=0;i<n;i++)
		{
			scanf("%s",a[i]);
		}
		deal(0, 0, n, n);
		printf("%d\n", sum);
	}
}