#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	int i;
	for(i=1;i<=t;i++)
	{
		long long int n,j,c,num,a,b;
		cin>>n;
		c=sqrt(n);
		long long int arr[n];
		if(c*c==n)
		cout<<-1<<endl;
		else
		{
		    c=0;
		   for(j=1;j<=sqrt(n);j++)
		   {
			   a=n/j;
			   b=n/a;
			   if(a*b==n&&abs(b-a)%2==0)
			   {
				   arr[c++]=((b-a)*(b-a))/4;
			   }
		   }
		   sort(arr,arr+c);
		   if(c==0)
		   cout<<-1<<endl;
		   else
		   cout<<arr[0]<<endl;
		}
	}
	return 0;
}
