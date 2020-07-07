/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 46152
 * Submitted at:  2017-12-14 12:28:29
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    750
 * Problem Name:  Closest Common Ancestor
 */

#include<stdio.h>
#include<string.h>

struct Node
{
	int father;
};

Node a[105];
int n;
int root;
int reached[105];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(reached,0,sizeof(reached));
		scanf("%d%d", &root, &n);
		int x,y;
		for(int i=0;i<n-1;i++)
		{
			scanf("%d%d",&x, &y);
			a[x].father=y;
		}
		scanf("%d%d",&x, &y);
		while(1)
		{
			reached[x]=1;
			if(x==root)
				break;
			x=a[x].father;
		}
		while(1)
		{
			if(reached[y]==1)
			{
				printf("%d\n",y);
				break;
			}
			if(y==root)
				break;
			y=a[y].father;
		}
	}
}

答复

转发