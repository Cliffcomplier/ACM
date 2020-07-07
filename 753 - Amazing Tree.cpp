/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 46448
 * Submitted at:  2017-12-15 22:33:02
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    753
 * Problem Name:  Amazing Tree
 */

#include<stdio.h>
#include<string.h>

char a[10000005]={0};

int res=0;

int find(int from, int to)
{
	if(from>to)
		return 0;

	int sum=1;
	int left=0;
	int leftbegin=0;
	for(int i=from+1;i<=to-1;i++)
	{
		if(a[i]=='(' && left ==0 )
		{
			left++;
			leftbegin=i;
		}
		else if(a[i]=='(')
			left++;
		else if(a[i]==')')
			left--;
		if(left==0)
		{
			sum+=find(leftbegin, i);
		}
	}
	res ^= sum;
	return sum;
}

int main()
{
	while(scanf("%s",a)!=EOF)
	{
		res=0;
		find(0, strlen(a)-1);
		printf("%d\n",res);
		memset(a,0,sizeof(a));
	}
}

答复

转发