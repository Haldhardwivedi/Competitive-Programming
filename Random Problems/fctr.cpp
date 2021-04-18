#include <bits/stdc++.h>

using namespace std;
int gcd(int a,int b);

int main()
{
	int t;
	cin>>t;
	int i;
	for(i=1;i<=t;i++)
	{
		int l,b;
		cin>>l>>b;
		cout<<gcd(l,b);
	}
}

int gcd(int a,int b)
{
	if(b==0)
	return(a);
	else 
	return(gcd(b,a%b));
}
