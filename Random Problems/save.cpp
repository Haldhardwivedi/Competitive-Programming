#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long int n;
		cin>>n;
		long int a[n];
		long int i;
		for(i=0;i<n;i++)
			cin>>a[i];
		long int b[n];
		long int pos=0;
		b[0]=a[0];
		for(i=1;i<n;i++)
		{
			if(a[i]>b[pos])
			{
				pos++;
				b[pos]=a[i];
			}
			else
			{
				long int c=pos;
				while(a[i]<b[c]&&c>=0)
					c--;
				b[c+1]=a[i];
			}
		}
		cout<<pos+1<<" ";
		for(i=0;i<=pos;i++)
		{
			cout<<b[i]<<" ";
		}
		cout<<endl;
	}
}