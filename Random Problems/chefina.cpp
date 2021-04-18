#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t;
	cin>>t;
	while(t--)
	{
		long long int n;
		cin>>n;
		long long int a[n],b[n],i,j,c[2*n],min=0;
		map<long long int,long long int> na,nb;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			na[a[i]]++;
				min=a[i];
		}
		for(j=0;j<n;j++)
		{
			scanf("%lld",&b[j]);
			nb[b[j]]++;
		}
		sort(a,a+n);
		sort(b,b+n);
		min=a[0];
		if(a[0]>b[0])
			min=b[0];
		int flag=0;
		for(i=0;i<n;i++)
		{
			if((na[a[i]]+nb[a[i]])%2==1)
			{
				flag=1;
				break;
			}
			else if((na[b[i]]+nb[b[i]])%2==1)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
			cout<<-1<<endl;
		else
		{
				j=0;
				long long int t=0;
				for(i=0;i<n;i++)
				{	
					if(abs(na[a[i]]-nb[a[i]])>0)
					{
						c[j++]=a[i];
						if(na[a[i]]>nb[a[i]])
						{
							na[a[i]]--;
							nb[a[i]]++;
						}
						else
						{
							nb[a[i]]--;
							na[a[i]]++;
						}
					}
					if(abs(nb[b[i]]-na[b[i]])>0)
					{
						c[j++]=b[i];
						if(nb[b[i]]>na[b[i]])
						{
							nb[b[i]]--;
							na[b[i]]++;
						}
						else
						{
							na[b[i]]--;
							nb[b[i]]++;
						}
					}
				}
				sort(c,c+j);
				long long int cost=0;
				for(i=0;i<j/2;i++)
				{
					if(c[i]>2*min)
						cost=cost+2*min;
					else
						cost=cost+c[i];
				}
				cout<<cost<<endl;
		}
	}
	return(0);
}