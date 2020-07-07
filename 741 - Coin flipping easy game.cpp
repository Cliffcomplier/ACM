/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 46018
 * Submitted at:  2017-12-11 17:24:34
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    741
 * Problem Name:  Coin flipping easy game
 */

#include<stdio.h>
#include<string.h>

int n,m;


int a[105]={0};
int b[2100][105]={0};
int c[2100]={0};
int d[2100]={0};

void input()
{
	char tem[105];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	for(int i=0;i<n;i++)
	{
		scanf("%s",tem);
		int sum=0;
		for(int j=0;j<strlen(tem);j++)
		{
			if(tem[j]=='1')
			{
				sum=sum*2+1;
			}
			else
			{
				sum=sum*2;
			}
		}
		a[i]=sum;
	}
}

int digit_sum(int x)
{
	int sum=0;
	while(x)
	{
		if((x%2)==1)
			sum++;
		x/=2;
	}
	return sum;
}


void deal()
{
	for(int i=0;i<(1<<m);i++)
	{
		c[i]=digit_sum(i);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<(1<<m);j++)
		{
			b[j][i]=a[i] ^ j;
		}
	}
	int res=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<(1<<m);j++)
		{
			if(c[b[j][i]]>c[b[j][i] ^ ((1<<m)-1)])
			{
				d[j]+=c[b[j][i]];
			}
			else
			{
				d[j]+=c[b[j][i] ^ ((1<<m)-1)];
			}
		}
	}
	for(int i=0;i<(1<<m);i++)
		if(res<d[i])
			res=d[i];
	printf("%d\n",res);
}

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		input();
		deal();
	}
}