/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 46156
 * Submitted at:  2017-12-14 12:45:54
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    752
 * Problem Name:  Task Manager
 */

#include<stdio.h>
#include<string.h>

struct Node
{
	int start, duration, priority;
	int index, end;
};

Node * high[105];
int beginhigh,endhigh;
Node * low[105];
int beginlow, endlow;
Node a[105];

int n;

void input()
{
	memset(high,0,sizeof(high));
	beginhigh=0;
	endhigh=0;
	memset(low,0,sizeof(low));
	beginlow=0;
	endlow=0;
	memset(a,0,sizeof(a));
	
	int r,w,p;

	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d", &r, &w, &p);
		a[i].start=r;
		a[i].duration=w;
		a[i].priority=p;
		a[i].index=i;
		if(p==0)
		{
			high[endhigh]=&a[i];
			endhigh++;
		}
		else
		{
			low[endlow]=&a[i];
			endlow++;
		}
	}
}

int min(int i, int j)
{
	return i<j ? i:j;
}

void deal()
{
	int curtime=0;
	while(1)
	{
		if(beginhigh >= endhigh && beginlow >= endlow)
			break;
		if(beginhigh<endhigh && curtime >= high[beginhigh]->start)
		{
			high[beginhigh]->end = curtime + high[beginhigh]->duration;
			curtime = high[beginhigh]->end;
			beginhigh++;
		}
		else if(beginlow<endlow && curtime >= low[beginlow]->start)
		{
			low[beginlow]->end = curtime + low[beginlow]->duration;
			curtime = low[beginlow]->end;
			beginlow++;
		}
		else if(beginhigh >= endhigh)
		{
			curtime = low[beginlow]->start;
		}
		else if(beginlow >= endlow)
		{
			curtime = high[beginhigh]->start;
		}
		else
		{
			curtime = min(low[beginlow]->start, high[beginhigh]->start);
		}
	}

	printf("%d",a[0].end);
	for(int i=1;i<n;i++)
	{
		printf(" %d", a[i].end);
	}
	printf("\n");
}