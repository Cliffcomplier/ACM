/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 46060
 * Submitted at:  2017-12-13 00:02:59
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    747
 * Problem Name:  Boring job
 */

#include<stdio.h>
#include<string.h>

struct Node
{
	int v;
	int index;
};

Node a[1005][1005];
int an;
int n,k;

int min(int i,int j)
{
	return i<j ? i:j;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int printfirst=0;
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[0][i].v);
			a[0][i].index=i+1;
		}
		an=0;
		for(int i=n;i>0;i--)
		{
			int maxv=-999999999;
			int maxindex=0;
			for(int j=0;j<min(k,i);j++)
			{
				if(maxv<a[an][j].v)
				{
					maxv=a[an][j].v;
					maxindex=j;
				}
			}
			int x=0;
			for(int j=min(k,i);j<i;j++)
			{
				a[an+1][x].v=a[an][j].v;
				a[an+1][x].index=a[an][j].index;
				x++;
			}
			for(int j=0;j<min(k,i);j++)
			{
				if(j==maxindex)
					continue;
				a[an+1][x].v=a[an][j].v-1;
				a[an+1][x].index=a[an][j].index;
				x++;
			}
			if(printfirst==0)
			{
				printf("%d",a[an][maxindex].index);
				printfirst=1;
			}
			else
			{
				printf(" %d", a[an][maxindex].index);
			}
			an++;
		}
		printf("\n");
	}
}

答复

转发