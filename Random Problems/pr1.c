#include <stdio.h> 
#include <stdlib.h> 
  
int count1=0;
int count2=0;


struct Node { 
    int data; 
    struct Node* next; 
}*head1=NULL,*temp,*head2=NULL; 
  
struct Node* add(int x,struct Node *head)
{
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
    new_node->data=x;
    if(head==NULL)
    {
        head=new_node;
        new_node->next=NULL;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new_node;
        new_node->next=NULL;
    }
    return(head);
}

void onescomplement(struct Node *head,int *count)
{
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==0)
            temp->data=1;
        else
            temp->data=0;
        temp=temp->next;
        *(count)=*(count)+1;
    }
}

void twoscompement(struct Node *head,int *count)
{
    int arr[*count];
    temp=head;
    int i=*count-1;
    while(temp!=NULL)
    {
        arr[i]=temp->data;
        i--;
        temp=temp->next;
    }
    int carry=1;
    for(i=0;i<*count;i++)
    {
        arr[i]=carry+arr[i];
        if(arr[i]==2)
        {
            arr[i]=0;
            carry=1;
        }
        else if(arr[i]==1)
        {
            carry=0;
        }
        else
            carry=0;
    }
    temp=head;
    i=*count-1;
    while(temp!=NULL)
    {
        temp->data=arr[i--];
        temp=temp->next;
    }
}

void show(struct Node *head)
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main() 
{ 
    printf("enter the length of first linked list\n");
    int n;
    scanf("%d",&n);
    int i;
    int num;
    printf("enter the linked list element 0 and 1 only \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        head1=add(num,head1);
    }
    onescomplement(head1,&count1);
    twoscompement(head1,&count1);
    printf("2's complement of l1 is :\n");
    show(head1);
    printf("enter the length of 2nd linked list\n");
    scanf("%d",&n);
    printf("enter the linked list element 0 and 1 only \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        head2=add(num,head2);
    }
    onescomplement(head2,&count2);
    twoscompement(head2,&count2);
    printf("2's complement of l2 is :\n");
    show(head2);
    return 0; 
} 