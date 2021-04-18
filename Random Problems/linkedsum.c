#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*tptr,*head;

void insert(int x);
void print();

int main()
{
	char num[100];
	printf("enter number 1\n");
	scanf("%s",num);
	int i=0;
	for(i=0;i<strlen(num);i++)
	{
		insert(num-48);
	}
return 0;
}

void insert()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	if(head==NULL)
	{
		head=temp;
		temp->next=NULL;
		tptr=head;
	}
