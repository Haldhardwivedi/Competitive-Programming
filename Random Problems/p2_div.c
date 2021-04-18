#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int l1=0;//length of first number
int l2=0;//length of second number
struct node
{
	int data;
	struct node *next;
}*head=NULL,*top=NULL,*head1=NULL,*head2=NULL,*tptr=NULL,*result=NULL;

void insert(int x);
int compare(struct node *tptr1,struct node *tptr2);
void division(struct node *tptr1,struct node *tptr2);
void subt(struct node *tptr1,struct node *tptr2);
struct node *reverse(struct node *temp);
void insertstack(int x);

//----------------MAIN HERE----------------------
int main()
{
	int i;
	char str[100];
	scanf("%s",str);
	for(i=0;i<strlen(str);i++)
		insert(str[i]-48);
		head1=head;
		head=NULL;
		l1=strlen(str);
	scanf("%s",str);
	for(i=0;i<strlen(str);i++)
		insert(str[i]-48);
		l2=strlen(str);
	head2=head;
	head=NULL;
	division(head1,head2);
	while(result!=NULL)
	{
		printf("%d ",result->data);
		result=result->next;
	}
	//printf("%d",compare(head1,head2));
	return 0;
}
//----------------------MAIN ENDS --------------------------//
//function to insert normally

void insert(int data)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	if(head==NULL)
	{
		tptr=temp;
		head=temp;
		temp->next=NULL;
	}
	else
	{
		tptr->next=temp;
		temp->next=NULL;
		tptr=temp;
	}
}
//insert ends above 

int compare(struct node *tptr1,struct node *tptr2)
{
	int c1=0;
	struct node *temp=tptr1;
	while(tptr1!=NULL)
	{
		c1++;
		tptr1=tptr1->next;
	}
	if(c1>l2)
	return 1;
	else if(c1<l2)
	return 2;
	else if(c1=l2)
	{
		while(temp!=NULL)
		{
			if(temp->data > tptr2->data)
			return 1;
			else if(temp->data < tptr2->data)
			return 2;
			temp=temp->next;
			tptr2=tptr2->next;
		}
		return 0;
	}
}

// compare function ends above
//stack insert function
void insertstack(int x)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node *));
	temp->data=x;
	if(top==NULL)
	{
		top=temp;
		temp->next=NULL;
		tptr=temp;
	}
	else
	{
		tptr->next=temp;
		top=temp;
	}
}
//multiplication statrs here
struct node * multi(struct node *temp,int x)
{
	struct node  *msub=NULL;
	temp=reverse(temp);
	int pro,carry=0;
	head=NULL;
	while(temp!=NULL)
		{
			pro=temp->data*x+carry;
			carry=pro/10;
			if(temp->next==NULL)
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
			temp=temp->next;
		}
		msub=head;
		head=NULL;
		msub=reverse(msub);
		return(msub);
}
void division(struct node *tptr1,struct node *tptr2)
{
	int i;
	struct node *sub=NULL;
	struct node *psub=NULL;
	int c=compare(tptr1,tptr2);
	while(c!=2)
	{
		head=NULL;
		for(i=1;i<=l2;i++)
		{
			insert(tptr1->data);
			tptr1=tptr1->next;
		}
		sub=head;
		head=NULL;
		int c1=compare(sub,tptr2);
		int num=2;
		if(c1==1||c1==0)
		{
			while(c1==1)
			{	
				psub=sub;
				sub=multi(sub,num);
				c1=compare(sub,tptr);
			}
			head=result;
			insert(num-1);
			result=head;
			head=NULL;
			top=NULL;
			psub=reverse(psub);
			tptr2=reverse(tptr2);
			subt(psub,tptr2);
			top=NULL;
			while(top!=NULL)
			{
				struct node *temp=(struct node *)malloc(sizeof(struct node));
				temp->data=top->data;
				temp->next=tptr1;
				tptr1=temp;
				top=top->next;
			}
			top=NULL;
			tptr2=reverse(tptr2);
		}
		c=compare(tptr1,tptr2);
	}
}
//subtract functions here!!!!
void subt(struct node *tptr1,struct node *tptr2)
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
	while(top->data==0)
	top=top->next;
}

struct node *reverse(struct node *temp)
{
	top=NULL;
	while(temp!=NULL)
	{
		insertstack(temp->data);
		temp=temp->next;
	}
	temp=top;
	top=NULL;
	return(temp);
}
