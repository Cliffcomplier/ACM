/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 46561
 * Submitted at:  2017-12-16 11:35:17
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    756
 * Problem Name:  Max-Heap
 */


#include<stdio.h>
#include<string.h>


int a[2000005];
int an;
int n;
char tem[105];
int k;

void insert()
{
	a[an]=k;
	int cur=an;
	an++;
	while(1)
	{
		int pre=cur/2;
		if(pre==0)
			break;
		if(a[pre]<a[cur])
		{
			int x=a[pre];
			a[pre]=a[cur];
			a[cur]=x;
			cur=cur/2;
		}
		else
		{
			break;
		}
	}
}

void pop()
{
	a[1]=a[an-1];
	an--;
	int cur=1;
	while(1)
	{
		if(cur>=an)
			break;
		if(cur*2>=an)
			break;
		if(cur*2+1>=an)
		{
			if(a[cur*2]>=a[cur])
			{
				int x=a[cur*2];
				a[cur*2]=a[cur];
				a[cur]=x;
				cur=cur*2;
			}
			else
			{
				break;
			}
			continue;
		}
		if(a[cur*2]>=a[cur*2+1])
		{
			if(a[cur*2]>=a[cur])
			{
				int x=a[cur*2];
				a[cur*2]=a[cur];
				a[cur]=x;
				cur=cur*2;
			}
			else
			{
				break;
			}
		}
		else
		{
			if(a[cur*2+1]>a[cur])
			{
				int x=a[cur*2+1];
				a[cur*2+1]=a[cur];
				a[cur]=x;
				cur=cur*2+1;
			}
			else
			{
				break;
			}
		}
	}
}

void print()
{
	int sum=0;
	for(int i=1;i<an;i++)
		sum+=a[i];
	printf("%d\n",sum);
}


int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		memset(a,0,sizeof(a));
		an=1;
		for(int i=0;i<n;i++)
		{
			scanf("%s",tem);
			if(tem[0]=='a')
			{
				scanf("%d",&k);
				insert();
			}
			else if(tem[0]=='p')
				pop();
			else if(tem[0]=='r')
				print();
		}
	}
}