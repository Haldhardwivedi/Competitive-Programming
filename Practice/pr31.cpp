/*
Haldhar Dwivedi
haldhardwivedi@gmail.com
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define PI 3.1415926535897932384626
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define br printf("\n")
#define fo(i, n) for(i=0;i<n;i++)
#define Fo(i, k, n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define deba(i, a, n) fo(i, n){cout << a[i] << " ";}
#define pb push_back
#define mp make_pair
#define F first
#define S second

const int mod = 1'000'000'007;
const int N = 3e5;


ll int max(ll int a,ll int b)
{
    if(a>b)
    return a;
    else 
    return b;
}

void solve() 
{
    ll int n,m;
    cin>>n>>m;
    ll int arr[n][m];
    ll int dp[n][m];
    ll int p = n, q = m;
    ll int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        cin>>arr[i][j];
    }

    dp[m-1][n-1] = arr[m-1][n-1] > 0? 1:abs(arr[m-1][n-1]) + 1;
  
    for ( i = m-2; i >= 0; i--)
         dp[i][n-1] = max(dp[i+1][n-1]-arr[i][n-1], 1);
    for ( j = n-2; j >= 0; j--)
         dp[m-1][j] = max(dp[m-1][j+1]-arr[m-1][j], 1);
  
    for (int i=m-2; i>=0; i--)
    {
        for (int j=n-2; j>=0; j--)
        {
            // int val = min(dp[i+1][j], dp[i][j+1]);
            // dp[i][j] = max(val - arr[i][j], 1);
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
     }
     cout<<dp[0][0]<<endl;
}


int main() 
{
    ll int t = 1;
    sl(t);
    while(t--) 
    {
        solve();
    }
    return 0;
}