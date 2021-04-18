#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char str[100];
		cin>>str;
		int i;
		map <char,int> val;
		int arr[5]={1,5,9,15,21};
		int num=1;
		char ch='a';
		for(i=0;i<26;i++)
		{
			val.insert(pair<char, int>(ch, num));
			ch++;
			num++;
		}
		int cost=0,j;
		int b[5]={0};
		for(i=0;i<strlen(str);i++)
		{
			num=val[str[i]];
			for(j=0;j<5;j++)
			{
				b[j]=abs(num-arr[j]);
			}
			sort(b,b+5);
			cost=cost+b[0];
		}
		cout<<cost<<endl;
	}
	return(0);
}