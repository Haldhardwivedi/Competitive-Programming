#include <bits/stdc++.h>
using namespace std;
int dp[1000001];
 
#define p 1000000007
 
int findWays(int N)
{
	if (N == 0) 
    {
		return 1;
	}
	int cnt = 0;
	for (int i = 1; i <= 6; i++) 
    {
 
		if (N - i >= 0) 
        {
            if(dp[N-i]!=-1)
            {
                cnt=((cnt)%p+(dp[N-i])%p)%p;
            }
            else
            {
                dp[N-i]=findWays(N - i);
                cnt=((cnt)%p+(dp[N-i])%p)%p;
            }
		}
	}
	return (cnt%p);
}
 
int main()
{
    memset(dp,-1,sizeof(dp));
	int N ;
    cin>>N;
	cout << findWays(N)<<endl;
	return 0;
}
