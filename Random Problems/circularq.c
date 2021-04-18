#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	if(front==NULL)
	{
