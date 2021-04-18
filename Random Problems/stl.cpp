#include <bits/stdc++.h> 
using namespace std;


int main()
{
	int n;
	cin>>n;
	int i=0;
	int arr[n];
	while(i<n)
	{
		cin>>arr[i++];
	}
	int a,b;
	int max=0,sum;
	for(a=0;a<n;a++)
	{
		for(b=a;b<n;b++)
		{
			sum=0;
			for(i=a;i<=b;i++)
			{
				sum=sum+arr[i];
			}
			if(sum>max)
				max=sum;
		}
	}
	cout<<max;			
	return 0;
}
