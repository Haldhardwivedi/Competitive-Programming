#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int q;
	cin>>q;
	int i;
	int m=4;
	vector<int> v[n]; 
	for(i=0;i<n;i++)
	{
		int k;
		cin>>k;
		int j;
		int num;
		for(j=0;j<k;j++)
		{
			cin>>num;
			v[i].push_back(num);
		}
	}
	for(i=0;i<q;i++)
	{
		int p,q;
		cin>>p>>q;
		cout<<v[p][q]<<endl;
	}
	return(0);
}
