#include<bits/stdc++.h>

using namespace std;

int main()
{
	long int t;
	cin>>t;
	while(t--)
	{
		long long int s,n;
		cin>>s>>n;
		long long int count=0;
		while(s)
		{
			if(s==1)
			{
				count++;
				s=0;
				break;
			}
			count=count+(s/n);
			s=s-(s/n)*n;
			n=n-2;
		}
		cout<<count<<endl;
	}

	return 0;
}
	