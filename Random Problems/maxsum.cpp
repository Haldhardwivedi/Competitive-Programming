#include<iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	int i;
	for(i=0;i<n;i++)
		cin>>arr[i];
	int best=0,sum=0;
	for(i=0;i<n;i++)
	{
		sum=sum+arr[i];
		best=max(best,sum);
	}
	cout<<best<<endl;
	return 0;
}
	
