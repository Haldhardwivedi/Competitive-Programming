#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long int a[n],b[n],sum=0,p1=0,p2=0;
		int i;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
			for(i=0;i<n;i++)
		{
			cin>>b[i];
		}
		for(i=0;i<n;i++)
		{
			if(a[i]==b[i]&&p1==p2)
			{
				sum=sum+a[i];
			}
			p1=p1+a[i];
			p2=p2+b[i];
		}
		cout<<sum<<endl;
	}
	return (0);
}