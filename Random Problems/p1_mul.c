#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count=0;
struct node 
{
	int data;
	struct node *next;
}*top=NULL,*head=NULL,*tptr=NULL,*head1=NULL,*head2=NULL,*add=NULL;

struct node * sum(struct node *tptr1,struct node *tptr2);
void multi();
void insert(int x);
void print1(struct node *temp);
void insertstack(int x);

int main()
{
	char str[100];
	int i;
	printf("enter elemnt\n");
	scanf("%s",str);
	for(i=strlen(str)-1;i>=0;i--)
		insert(str[i]-48);
		head1=head;
		head=NULL;
		printf("enter elemnt\n");
	scanf("%s",str);
	for(i=strlen(str)-1;i>=0;i--)
		insert(str[i]-48);
		head2=head;
		head=NULL;
		multi();
		while(add!=NULL)
		{
				insertstack(add->data);
				add=add->next;
		}
		print1(top);
		return 0;
}

void multi()
{
	struct node *tptr1=head1;
	struct node *tptr2=head2;
	int carry=0;
	int pro=0;
	int i;
	while(tptr2!=NULL)
	{
		head=NULL;
		tptr1=head1;
		for(i=0;i<count;i++)
			{
				insert(0);
			}
			count++;
		while(tptr1!=NULL)
		{
			pro=tptr2->data*tptr1->data+carry;
			carry=pro/10;
			if(tptr1->next==NULL)
			{
				if(pro/10==0)
				insert(pro);
				else
				{
					insert(pro%10);
					pro=pro/10;
					insert(pro);
				}
			}
			else
			
			{
				pro=pro%10;
				insert(pro);
			}
			tptr1=tptr1->next;
		}
		struct node *temp=head;
		struct node *sum1=add;
		if(sum1==NULL)
		add=temp;
		else
		add=sum(sum1,temp);
		tptr2=tptr2->next;
	}
}

struct node * sum(struct node *tptr1,struct node *tptr2)
{
	head=NULL;
	int sum1=0;
	while(tptr1->next!=NULL&&tptr2->next!=NULL)
	{
		sum1=sum1+tptr1->data+tptr2->data;
		insert(sum1%10);
		sum1=sum1/10;
		tptr1=tptr1->next;
		tptr2=tptr2->next;
	}
	if(tptr1->next==NULL && tptr2->next==NULL )
	{
		sum1=sum1+tptr2->data+tptr1->data;
			insert(sum1);
	}
	else if(tptr1->next==NULL)
	{
		sum1=sum1+tptr2->data+tptr1->data;
		insert(sum1%10);
		sum1=sum1/10;
		tptr2=tptr2->next;
		while(tptr2->next!=NULL)
		{
			sum1=sum1+tptr2->data;
			insert(sum1%10);
			sum1=sum1/10;
			tptr2=tptr2->next;
		}
		sum1=sum1+tptr2->data;
			insert(sum1);
	}
	else if(tptr2->next==NULL)
	{
		sum1=sum1+tptr2->data+tptr1->data;
		insert(sum1%10);
			sum1=sum1/10;
			tptr1=tptr1->next;
		while(tptr1->next!=NULL)
		{
			sum1=sum1+tptr1->data;
			insert(sum1%10);
			sum1=sum1/10;
			tptr1=tptr1->next;
		}
		sum1=sum1+tptr1->data;
			insert(sum1);
	}
	return(head);
}
void print1(struct node *temp)
{
	tptr=temp;
	printf("multiplication is \n");
	while(tptr->next!=NULL)
	{
		printf("%d",tptr->data);
		tptr=tptr->next;
	}		
	printf("%d ",tptr->data);
	printf("\n");
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
