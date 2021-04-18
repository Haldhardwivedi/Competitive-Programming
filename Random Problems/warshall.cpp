#include<bits/stdc++.h>
using namespace std;
int min1(int a,int b);
int main()
{
	int n;
	cin>>n;
	int r,c,w;
	int arr[n][n]={500};
	int e;
	cout<<"enter edges "<<endl;
	cin>>e;
	for(r=0;r<e;r++)
	{
		cin>>r>>c>>w;
		arr[r][c]=w;
	}
	int k;
	vector <int> v[n];
	vector <int> :: iterator it[n];
	for(k=0;k<n;k++)
	{
		for(r=0;r<n;r++)
		{
			it[r]=v[r].begin();
			for(c=0;c<n;c++)
			{
				arr[r][c]=min1(arr[r][k]+arr[k][c],arr[r][c]);
				if(arr[r][k]+arr[k][c]<arr[r][c])
				{
					v[c].push_back(k);
				}
			}
		}
	}
	cout<<"enter the pair of vertex to find distance"<<endl;
	cin>>r>>c;
	cout<<arr[r][c]<<endl;

}
int min1(int a,int b)
{
	if(a>b)
		return(a);
	else
		return(b);
}