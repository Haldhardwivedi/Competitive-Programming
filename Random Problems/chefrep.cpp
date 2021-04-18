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
		int arr[n],i;
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		int max1=*max_element(arr,arr+n)+1;
		int visit[max1]={0},c=0;
		//cout<<max1<<endl;
		for(i=0;i<n;i++)
		{
			if(visit[arr[i]]>0&&arr[i]!=arr[i-1])
			{
				//cout<<arr[i]<<endl;
				c=1;
				break;
			}
			visit[arr[i]]++;
		}
		if(c==1)
		cout<<"NO"<<endl;
		else
		{
			sort(visit,visit+max1,greater<int>());
			i=0;
			while(i<max1 && visit[i]!=0)
			{
				if(visit[i]==visit[i+1])
				{
					c=1;
					break;
				}
				i++;
			}
			if(c==1)
			cout<<"NO"<<endl;
			else
			cout<<"YES"<<endl;
		}
	}
	return 0;
}