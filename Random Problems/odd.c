#include<stdio.h>
#include<stdlib.h>

int main()
{
	int t;
	scanf("%d",&t);
    long	int j,sum;
	long int result[t];
	for(j=0;j<t;j++)
	{
		int n,m,q,i;
		scanf("%d%d%d",&n,&m,&q);
		int row[n];
		int col[m];
		int r,c;
		for(r=0;r<n;r++)
		    row[r]=0;
		for(c=0;c<m;c++)
		    col[c]=0;
		while(q)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			row[x-1]=row[x-1]+1;
			col[y-1]=col[y-1]+1;
				q--;
		}
		 sum=0;
		for(r=0;r<n;r++)
		{
				if(row[r]%2==0)
				{
					for(c=0;c<m;c++)
					if(col[c]%2!=0)
					sum++;
				}
				else
				{
				    for(c=0;c<m;c++)
					if(col[c]%2==0)
					sum++;
				}
		}
		result[j]=sum;
	}
	for(j=0;j<t;j++)
		printf("%ld ",result[j]);
	return 0;
}
