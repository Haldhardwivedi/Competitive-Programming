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
    ll int n;
    cin>>n;
    ll int a[n];
    ll int b[n];
    vector<pair<ll int,ll int>>c;
    ll int i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        c.push_back(make_pair(a[i],i));
    }
    sort(c.begin(),c.end());
    ll int val=0;
    for(i=0;i<n;i++)
    {
        if(c[i].first>val)
        {
            c[i].first=val;
            val++;
        }
    }
    sort(c.begin(),c.end(),sortbysec);
    for(i=0;i<n;i++)
    {
        cout<<b[i]<<" ";
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
