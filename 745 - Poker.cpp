/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 46058
 * Submitted at:  2017-12-13 00:01:25
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    745
 * Problem Name:  Poker
 */


#include<stdio.h>
#include<string.h>

int n,m;
int dp[100005]={0};
char b[105];

int max(int a, int b)
{
	return a>b ? a:b;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			if(i==0)
				dp[i]=x;
			else
				dp[i]=max(dp[i-1],x);
		}
		scanf("%d",&m);
		while(m--)
		{
			scanf("%s",b);
			if(b[0]=='m')
			{
				printf("%d\n", dp[n-1]);
			}
			else if(b[0]=='r')
			{
				n--;
			}
			else if(b[0]=='a')
			{
				int x;
				scanf("%d",&x);
				if(n==0)
					dp[n]=x;
				else
					dp[n]=max(dp[n-1], x);
				n++;
			}
		}
	}

}

答复

转