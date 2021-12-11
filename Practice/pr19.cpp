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

ll int n;
int grid[1000001][1000001];

int path(int x,int y)
{
    if(x>n||y>n)
    return 0;
    if(x==n&&y==n)
    return(1);
    else if(grid[x][y]==0)
    return(0);
    else if(grid[x][y]==1)
    {
        int val=path(x+1,y)||path(x,y+1);
        return(val);
    }
}

void solve() 
{
    cin>>n;
    ll int x,y,i,j;
    // int grid[n+1][n+1];
    //memset(grid,1,sizeof(grid));
    for(i=0;i<n;i++)
    {
        cin>>x>>x;
        grid[x][y]=0;
    }
    if(path(1,1)==1)
    cout<<"YES"<<endl;
    else 
    cout<<"NO"<<endl;
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