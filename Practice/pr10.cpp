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


bool sortbysec(const pair<ll int,ll int> &a,const pair<ll int,ll int> &b)
{
    return (a.second < b.second);
}

void solve() 
{
    ll int n,m;
    cin>>n>>m;
    vector<ll int> arr[n+2];
    ll int i,j;
    ll int x,y;
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    vector<pair<ll int,ll int>>v;
    for(i=1;i<=n;i++)
    {
        ll int count=arr[i].size();
        v.push_back(make_pair(count,i));
    }
    sort(v.begin(),v.end());
    ll int val=n;
    for(i=0;i<v.size();i++)
    {
        v[i].first=val;
        val--;
    }
    sort(v.begin(),v.end(),sortbysec);
    ll int d[n+1]={0};
    for(i=1;i<=n;i++)
    {
        ll int count=0;
        for(j=0;j<=arr[i].size();j++)
        {
            if(v[i-1].first>v[arr[i][j]-1].first)
            count++;
        }
        d[i-1]=count;
    }
    sort(d,d+n);
    cout<<d[n-1]-d[0]<<endl;
    for(i=0;i<v.size();i++)
    {
        cout<<v[i].first<<" ";
    }
    cout<<endl;
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