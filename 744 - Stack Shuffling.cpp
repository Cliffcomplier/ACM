/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 46057
 * Submitted at:  2017-12-13 00:00:09
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    744
 * Problem Name:  Stack Shuffling
 */

#include<stdio.h>
#include<string.h>

int t;
int n;
int a[10005];
int an;
int b[10005];
int bn;
int s[10005];
int sn;
int m;

void deal()
{
	bn=0;
	sn=0;
	an=n;
	for(int i=0;i<n;i++)
	{
		while(1)
		{
			if(sn==0)
			{
				if(an==0)
				{
					printf("Impossible\n");
					return ;
				}
				an--;
				s[sn++]=a[an];
			}
			else if(s[sn-1]!=b[i])
			{
				if(an==0)
				{
					printf("Impossible\n");
					return ;
				}
				an--;
				s[sn++]=a[an];
			}
			else if(s[sn-1]==b[i])
			{
				sn--;
				break;
			}
		}
	}
	printf("Aye\n");
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		an=n;
		bn=0;
		sn=0;
		scanf("%d",&m);
		while(m--)
		{
			for(int i=0;i<n;i++)
				scanf("%d",&b[i]);
			deal();
		}
	}
}