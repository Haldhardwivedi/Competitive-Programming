#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int a[n],i;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		long int start=1;
		i=0;
		int flag=0;
		while(a[i]<m)
		{
			if(a[i]!=start)
			{
				flag=1;
				break;
			}
			else
			{
				i++;
				start++;
			}
		}
		if(flag==1)
			cout<<-1<<endl;
		else
		{
			long int count=0;
			for(i=0;i<n;i++)
			{
				if(a[i]==m)
					count++;
			}
			cout<<n-count<<endl;
		}
	}
	return 0;
}