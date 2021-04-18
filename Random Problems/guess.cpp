#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long int a[n],min=0;
		int i;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		min=a[0];
		for(i=1;i<n;i++)
		{
			if(a[i]>a[i-1])
			{
				a[i]=(a[i-1]+a[i])/2;
			}
		}
	}
}