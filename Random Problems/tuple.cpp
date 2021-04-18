#include<bits/stdc++.h>

using namespace std;
int count(long long int p,long long int q,long long int r,long long int a,long long int b,long long int c);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int p,q,r,a,b,c,n;
		cin>>p>>q>>r;
		cin>>a>>b>>c;
		n=count(p,q,r,a,b,c);
		cout<<n<<endl;
	}
}

int count(long long int p,long long int q,long long int r,long long int a,long long int b,long long int c)
{
	if(p==a)
	{
		if(q==b)
		{
			if(r==c)
				return(0);
			else
				return(1);
		}
		else if(r==c)
			return(1);
		else
		{
			if(b-q==c-r)
				return(1);
			else if(q!=0&&r!=0)
			{
				if(b%q==0&&c%r==0)
				{
					if(b/q==c/r)
						return(1);
				}
			}
			return(2);
		}
	}
	else if(q==b)
		return(count(q,p,r,b,a,c));
	else if(r==c)
		return(count(r,p,q,c,a,b));
	else
	{
		long long int d[22];
		d[0]=a-p;
		d[1]=b-q;
		d[2]=c-r;
		if(d[0]==d[1]&&d[1]==d[2])
			return(1);
		if(p!=0&&q!=0&&r!=0)
		{
			d[0]=a/p;
			d[1]=b/q;
			d[2]=c/r;
			if(a%p==0&&b%q==0&&c%r==0)
			{
				if(d[0]==d[1]&&d[1]==d[2])
					return(1);
			}
			if(d[0]==d[1]&&a%p==0&&b%q==0||d[0]==d[2]&&a%p==0&&c%r==0||d[1]==d[2]&&c%r==0&&b%q==0)
			{
				return(2);
			}
		}
		d[0]=a-p;
		d[1]=b-q;
		d[2]=c-r;
		if(d[0]==d[1]||d[0]==d[2]||d[1]==d[2])
			return(2);
		if((p-q)!=0&&(q-r)!=0&&(r-p)!=0)
		{
			d[0]=(a-b)/(p-q);
			d[1]=(b-c)/(q-r);
			d[2]=(c-a)/(r-p);
			if((a-b)%(p-q)==0&&(b-c)%(q-r)==0&&(c-a)%(r-p)==0)
			{
				if(d[0]==d[1]&&d[1]==d[2])
					return(2);
			}
		}
		if(p!=0&&r!=0)
		{
			long int x,y;
			x=a-(b-q);
			y=c-(b-q);
			if(x/p==y/r&&x%p==0&&y%r==0)
				return(2);
		}
		if(q!=0&&r!=0)
		{
			long int x,y;
			x=b-(a-p);
			y=c-(a-p);
			if(x/q==y/r&&x%q==0&&y%r==0)
				return(2);	
		}
		if(p!=0&&q!=0)
		{
			long int x,y;
			x=a-(c-r);
			y=b-(c-r);
			if(x/p==y/q&&x%p==0&&y%q==0)
				return(2);
		}
		for(int i=0;i<22;i++)
			d[i]=4;
		d[0]=1+count(a,q+(a-p),r,a,b,c);
		d[1]=1+count(a,q,r+(a-p),a,b,c);
		d[2]=1+count(a,q+(a-p),r+(a-p),a,b,c);
		d[3]=1+count(p,b,r+(b-q),a,b,c);
		d[4]=1+count(p+(b-q),b,r,a,b,c);
		d[5]=1+count(p+(b-q),b,r+(b-q),a,b,c);
		d[18]=1+count(p+(c-r),q,c,a,b,c);
		d[19]=1+count(p,q+(c-r),c,a,b,c);
		d[20]=1+count(p+(c-r),q+(c-r),c,a,b,c);
		if(p!=0)
		{
			if(a%p==0)
			{
				d[6]=1+count(a,q*(a/p),r,a,b,c);
				d[7]=1+count(a,q,r*(a/p),a,b,c);
				d[8]=1+count(a,q*(a/p),r*(a/p),a,b,c);
			}
		}
		if(q!=0)
		{
			if(b%q==0)
			{
				long int t1;
				t1=b/q;
				d[9]=1+count(p*t1,b,r,a,b,c);
				d[10]=1+count(p,b,r*t1,a,b,c);
				d[11]=1+count(p*t1,b,r*t1,a,b,c);
			}
		}
		if(r!=0)
		{
			if(c%r==0)
			{
				long int t1;
				t1=c/r;
				d[12]=1+count(p*t1,q,c,a,b,c);
				d[13]=1+count(p,q*t1,c,a,b,c);
				d[14]=1+count(p*t1,q*t1,c,a,b,c);
			}
		}
		d[15]=1+count(a,q,r,a,b,c);
		d[16]=1+count(p,b,r,a,b,c);
		d[17]=1+count(p,q,c,a,b,c);
		sort(d,d+21);
		return(d[0]);
	}
}