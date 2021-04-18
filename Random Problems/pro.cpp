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
		int i;
		int a[n];
		for(i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		int c=0;
		for(i=0;i<n-1;i++)
		{
			if(a[i]==a[i+1])
			{
				c=1;
				break;
			}
		}
		if(c==0)
		{
			cout<<"YES"<<endl;
			for(i=0;i<n;i++)
				cout<<a[i]<<" ";
			cout<<endl;
		}
		else
			cout<<"NO"<<endl;
	}
	return(0);
}