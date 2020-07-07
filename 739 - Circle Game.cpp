/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 46005
 * Submitted at:  2017-12-11 15:51:17
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    739
 * Problem Name:  Circle Game
 */

#include<stdio.h>


class Node
{
public:
	Node * next;
	Node * prev;
	int tag;
	Node(Node* prev, Node* next, int tag)
	{
		this->prev=prev;
		this->next=next;
		this->tag=tag;
	}
};

int n;
int q;
Node * root = NULL;
Node * tail = NULL;
Node * cur = NULL;

void next(int i)
{
	i%=n;
	for(int j=0;j<i;j++)
	{
		cur = cur->next;
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		if(root == NULL)
		{
			root = new Node(NULL, NULL, x);
			tail = root;
		}
		else
		{
			Node * tem = new Node(tail, NULL, x);
			tail->next = tem;
			tail = tem;
		}
	}
	tail->next = root;
	root->prev = tail;
	cur = root;

	scanf("%d",&q);
	while(q--)
	{
		int a, i, tag;
		scanf("%d",&a);
		if(a==1)
		{
			scanf("%d%d",&i, &tag);
			i%=n;
			if(i==0)
				i=n;
			next(i-1);
			Node * tem = new Node(cur, cur->next, tag);
			cur->next = tem;
			tem->next->prev = tem;
			cur = cur->next;
			n++;
		}
		else if(a==2)
		{
			scanf("%d",&i);
			i%=n;
			if(i==0)
				i=n;
			next(i-1);
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
			cur = cur->next;
			n--;
		}
		else if(a==3)
		{
			scanf("%d",&i);
			i%=n;
			if(i==0)
				i=n;
			next(i-1);
			printf("%d\n", cur->tag);
		}
	}
}

答复