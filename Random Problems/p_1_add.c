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
void sum ();
void print1(struct node *temp);
void insertstack(int x);
//main function

int main()
{
	char str[100];
	printf("enter number 1\n:");
	scanf("%s",str);
	int i;
	for(i=strlen(str)-1;i>=0;i--)
		insert(str[i]-48);
	head1 = head;
	//print1(head1);
	head=NULL;
	printf("enter number 2\n:");
	scanf("%s",str);
	for(i=strlen(str)-1;i>=0;i--)
		insert(str[i]-48);
	head2 = head;
	//print1(head2);
	sum();
	head3=top;
	print1(head3);
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


void sum()
{
	int sum1=0;
	struct node *tptr1,*tptr2;
	tptr1=head1;
	tptr2=head2;
	while(tptr1->next!=NULL&&tptr2->next!=NULL)
	{
		sum1=sum1+tptr1->data+tptr2->data;
		insertstack(sum1%10);
		sum1=sum1/10;
		tptr1=tptr1->next;
		tptr2=tptr2->next;
	}
	if(tptr1->next==NULL && tptr2->next==NULL )
	{
		sum1=sum1+tptr2->data+tptr1->data;
			insertstack(sum1);
	}
	else if(tptr1->next==NULL)
	{
		sum1=sum1+tptr2->data+tptr1->data;
		insertstack(sum1%10);
		sum1=sum1/10;
		tptr2=tptr2->next;
		while(tptr2->next!=NULL)
		{
			sum1=sum1+tptr2->data;
			insertstack(sum1%10);
			sum1=sum1/10;
			tptr2=tptr2->next;
		}
		sum1=sum1+tptr2->data;
			insertstack(sum1);
	}
	else if(tptr2->next==NULL)
	{
		sum1=sum1+tptr2->data+tptr1->data;
		insertstack(sum1%10);
			sum1=sum1/10;
			tptr1=tptr1->next;
		while(tptr1->next!=NULL)
		{
			sum1=sum1+tptr1->data;
			insertstack(sum1%10);
			sum1=sum1/10;
			tptr1=tptr1->next;
		}
		sum1=sum1+tptr1->data;
			insertstack(sum1);
	}
}
			

void print1(struct node *temp)
{
	tptr=temp;
	printf("sum is \n");
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
