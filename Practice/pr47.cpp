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



void solve() 
{
    ll int n;
    cin>>n;
    ll int a[n];
    ll int i;
    ll int sum=0;
    ll int count=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        sum=sum+a[i];
    }
    if(sum%3!=0)
    {
        cout<<-1<<endl;
    }
    else 
    {
        vector<ll int>v;
        for(i=0;i<n;i++)
        {
            if(a[i]%3!=0)
            v.push_back(a[i]);
        }
        //cout<<v.size()<<endl;
        sort(v.begin(),v.end());
        map<int,vector<int>>m;
        int flag=1;
        for(i=0;i<v.size();i++)
        {
            m[v[i]%3].push_back(v[i]);
        }
        if(m[1].size()==m[2].size())
        {
            cout<<m[1].size()<<endl;
        }
        else 
            cout<<-1<<endl;
    }
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