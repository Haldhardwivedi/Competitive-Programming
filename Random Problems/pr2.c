#include<stdio.h>
#include<stdlib.h>

int HEAP_SIZE = 30;
int heapSize=0;

struct Heap
{
    int id;
    int arr[20];
    int size;
}heap[30];

void Insert(int id,int *a,int n) 
{
    heapSize++;
    heap[heapSize].id= id; 
    int now = heapSize;
    while (heap[now / 2].id > id) 
    {
        heap[now].id = heap[now / 2].id;
        now /= 2;
    }
    heap[now].id = id;
    int i;
    heap[now].size=n;
    for(i=0;i<n;i++)
    {
        heap[now].arr[i]=a[i];
    }
}
 
int DeleteMin() 
{
    int minElement, lastElement, child, now;
    minElement = heap[1].id;
    lastElement = heap[heapSize--].id;
    for (now = 1; now * 2 <= heapSize; now = child)
    {
        child = now * 2;
        if (child != heapSize && heap[child + 1] .id< heap[child].id) 
        {
            child++;
        }
        if (lastElement > heap[child].id) 
        {
            heap[now].id = heap[child].id;
        } 
        else /* It fits there */
        {
            break;
        }
    }
    heap[now].id = lastElement;
    return minElement;
}

void Display(int id)
{
    int i;
    for(i=1;i<=heapSize;i++)
    {
        if(heap[i].id==id)
        {
            int j;
            for(j=0;j<heap[i].size;j++)
                printf("%d  ",heap[i].arr[j]);
            printf("\n");
            break;
        }
    }
}

int Search(int id)
{
    int i;
    for(i=1;i<=heapSize;i++)
    {
        if(heap[i].id==id)
        {
            return(1);
        }
    }
    return(0);
}

int main()
{
    int flag=1;
    int i;
    int n;
    while(flag)
    {
        printf("hey welcome to  xyz hospital choose from the following options : \n");
        printf("Sample Menu: \n");
        printf("1. Patient In \n");
        printf("2. Patient Out \n");
        printf("3. Display Records \n");
        printf("4. Search \n");
        int choice;
        scanf("%d",&choice);
        int id;
        switch(choice)
        {
            case 1 :
                    printf("enter the id \n");
                    scanf("%d",&id);
                    printf("enter the length of Records \n");
                    scanf("%d",&n);
                    printf("enter the Records for id %d \n",id);
                    int a[10];
                    for(i=0;i<n;i++)
                        scanf("%d",&a[i]);
                    Insert(id,a,n);
                    break;
            case 2 :
                    printf("Patient out id is  %d:\n",DeleteMin());
                    break;
            case 3:
                   printf("enter the id of the Patient to Display his Records\n");
                   scanf("%d",&id);
                   printf("Records :");
                   Display(id);
                   break;
            case 4 :
                   printf("enter the id of the Patient to Search\n");
                   scanf("%d",&id);
                   if(Search(id)==1)
                    printf("Record is active\n");
                   else 
                    printf("Patient Record not found\n");
                break;

            default :
                            printf("invalid choice\n");
        }
        printf("wanna try again enter 1 for yes 0 for no\n");
        scanf("%d",&flag);
        //system(“clear”);
    }
    return 0;
}