/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 46043
 * Submitted at:  2017-12-12 10:19:55
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    743
 * Problem Name:  Syntax Checker
 */

#include<stdio.h>
#include<string.h>

struct Node
{
	int index;
	char ch;
};

Node st[1000005];
int stn=0;
char a[1000005];

void deal()
{
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]=='(' || a[i]=='[' || a[i]=='{')
		{
			st[stn].ch=a[i];
			st[stn].index=i+1;
			stn++;
		}
		else if(a[i]==')' || a[i]==']' || a[i]=='}')
		{
			if(stn==0)
			{
				printf("%d\n",i+1);
				return;
			}
			else if(a[i]==')')
			{
				if(st[stn-1].ch!='(')
				{
					printf("%d\n",i+1);
					return;
				}
				else
					stn--;
			}
			else if(a[i]==']')
			{
				if(st[stn-1].ch!='[')
				{
					printf("%d\n",i+1);
					return;
				}
				else
					stn--;
			}
			else if(a[i]=='}')
			{
				if(st[stn-1].ch!='{')
				{
					printf("%d\n",i+1);
					return;
				}
				else
					stn--;
			}
		}
		else
		{
			;
		}
	}
	if(stn==0)
		printf("Success\n");
	else
		printf("%d\n", st[0].index);
}


int main()
{
	while(gets(a))
	{
		stn=0;
		deal();
	}
}