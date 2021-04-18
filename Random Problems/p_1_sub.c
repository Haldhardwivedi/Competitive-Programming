#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure of node
struct node 
{
	int data;
	struct node *next;
}*top=NULL,*head=NULL,*tptr=NULL,*head1=NULL,*head2=NULL,*head3=NULL;

//functions declarations
void insert(int x);
void sub(struct node *head1,struct node *tptr2);
void print1(struct node *temp);
void insertstack(int x);
void pop();
//main function

int main()
{
	char str[100];
	int l1,l2;
	printf("enter number 1\n:");
	scanf("%s",str);
	l1=strlen(str);
	int i;
	for(i=strlen(str)-1;i>=0;i--)
		insert(str[i]-48);
	head1 = head;
	//print1(head1);
	head=NULL;
	printf("enter number 2\n:");
	scanf("%s",str);
	l2=strlen(str);
	for(i=strlen(str)-1;i>=0;i--)
		insert(str[i]-48);
	head2 = head;
	//print1(head2);
	int c=1;
	if(l1>l2)
		sub(head1,head2);
	else if(l1<l2)
		sub(head2,head1);
	else
		{
			struct node *tptr1=head1;
			struct node *tptr2=head2;
			while(tptr1!=NULL)
			{
				if(tptr1->data!=tptr2->data)
				{
					if(tptr1->data>tptr2->data)
							sub(head1,head2);
					else
						sub(head2,head1);
						break;
				}
				tptr1=tptr1->next;
				tptr2=tptr2->next;
			}
		}
	while(top->data==0)
	{
		pop();
	}
	print1(top);
	return 0;
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


void sub(struct node *tptr1,struct node *tptr2)
{
	int borrow=0;
	int dif;
	while(tptr1->next!=NULL&&tptr2->next!=NULL)
	{
		if(tptr1->data>=tptr2->data)
		{
			dif=tptr1->data-tptr2->data;
			insertstack(dif);
		}
		else
		{
			tptr1->data=tptr1->data-borrow;
			if(tptr1->data >= tptr2->data)
			{
				dif=tptr1->data-tptr2->data;
				insertstack(dif);
			}
			else
			{
				tptr1->data=tptr1->data+10;
				insertstack(tptr1->data - tptr2->data);
				borrow=1;
			}
		}
			tptr1=tptr1->next;
			tptr2=tptr2->next;
	}
	tptr1->data=tptr1->data-borrow;
	if(tptr1->next==NULL && tptr2->next==NULL )
	{
		dif=tptr1->data-tptr2->data;
		insertstack(dif);
	}
	else 
	{
		dif=tptr1->data-tptr2->data;
		insertstack(dif);
		tptr1=tptr1->next;
		while(tptr1!=NULL)
		{
			insertstack(tptr1->data);
			tptr1=tptr1->next;
		}
	}
}
			

void print1(struct node *temp)
{
	tptr=temp;
	printf("difference is \n");
	while(tptr->next!=NULL)
	{
		printf("%d",tptr->data);
		tptr=tptr->next;
	}		
	printf("%d ",tptr->data);
	printf("\n");
}

void insertstack(int x)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	if(top==NULL)
	{
		top=temp;
		temp->next=NULL;
	}
	else
	{
		temp->next=top;
		top=temp;
	}
}

void pop()
{
	top=top->next;
}
