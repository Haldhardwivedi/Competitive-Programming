#include<bits/stdc++.h>

using namespace std;
long long int binexp(long long int a,long long int b);

int main()
{
	long long int a,b;
	cin>>a>>b;
	cout<<binexp(a,b)<<endl;
}

long long int binexp(long long int a,long long int b)
{
	if(b==0)
		return(1);
	if(b%2==0)
		return(pow(binexp(a,b/2),2));
	else
		return(pow(binexp(a,b/2),2)*a);
}