#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int data;
	struct node *next;
}*head=NULL,*tptr=NULL,*nptr=NULL;

void insert(int x);
void print1(struct node *temp);
void reverse();

int main()
{
	char str[10];
	scanf("%s",str);
	int i=0;
	for(i=0;i<strlen(str);i++)
		insert(str[i]-48);
	 reverse();
	printf("reversed linked list\n");
	print1(head);
}

void insert(int x)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	if(head==NULL)
	{
		head=temp;
		temp->next=NULL;
		tptr=head;
	}
	else
	{
		tptr->next=temp;
		temp->next=NULL;
		tptr=temp;
	}
}

void reverse()
{
	struct node *temp;
	temp=head;
	tptr=head;
	struct node *tptr1=head;
	while(tptr1->next!=NULL)
	{
		tptr1=tptr1->next;
	}
	while(temp!=tptr1)
	{
		if(temp==head)
		{
			temp=temp->next;
			tptr->next=NULL;
		}
		else
		{
			nptr=temp;
			temp=temp->next;
			nptr->next=tptr;
			tptr=nptr;
		}
	}
	head=temp;
		temp->next=tptr;
}

void print1(struct node *temp)
{
	while(temp->next!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
	}		
	printf("%d ",temp->data);
	printf("\n");
}	
