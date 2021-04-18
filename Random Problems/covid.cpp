#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,p,y;
		cin>>n>>p;
		int arr[n][n];
		int q,x=0,r1=0,r2=0,c1=0,c2=0;
		while(x!=-1)
		{
			for(r1=0;r1<n;r1++)
			{
				for(c1=0;c1<n;c1++)
				{
					cout<<1<<" "<<r1<<" "<<r1<<" "<<c1<<" "<<c1<<endl;
					cin>>x;
					if(x==1)
					arr[r1][c1]=1;
					else
						arr[r][c]=0;
				}
			}
			x=-1;
		}
		cout<<2<<endl;
		for(r1=0;r1<n;r1++)
		{
			for(c1=0;c1<n;c1++)
				cout<<arr[r1][c1];
			cout<<endl;
		}
		cin>>y;
		if(y==-1)
			break;
	}
}