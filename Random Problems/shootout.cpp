#include<bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		char str[2*n];
		int i;
		for(i=0;i<2*n;i++)
			cin>>str[i];
		int a=0,b=0,s=n;
		for(i=0;i<n;i=i+1)
		{
			if(str[2*i]=='1')
				a++;
			if(a>b&&a>b+(n-i-1))
			{
				s=i+1;
				break;
			}
			else if(b>a&&b>a+(n-i-1))
			{
				s=i+1;
				break;
			}
			if(str[2*i+1]=='1')
				b++;
			if(a>b&&a>b+(n-i-1))
			{
				s=i+1;
				break;
			}
			else if(b>a&&b>a+(n-i-1))
			{
				s=i+1;
				break;
			}
		}
	cout<<2*s<<endl;
	}
	return 0;
}