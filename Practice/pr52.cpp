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
    ll int n,a,b;
    cin>>n>>a>>b;
    set<ll int>s,t;
    map<ll int,ll int>m;
    ll int i;
    s.insert(a);
    t.insert(b);
    for(i=n;i>a;i--)
    {
        if(i>a&&i!=b)
        {
            s.insert(i);
            m[i]++;
        }
        if(s.size()==n/2)
        {
            break;
        }
    }
    if(s.size()<n/2)
    {
        cout<<-1<<endl;
    }
    else 
    {
        for(i=1;i<b;i++)
        {
            if(i<b&&i!=a)
            {
                t.insert(i);
            }
            if(t.size()==n/2)
            {
                break;
            }
        }
        if(t.size()<n/2)
        cout<<-1<<endl;
        else 
        {
            for(auto it=s.begin();it!=s.end();it++)
            cout<<*it<<" ";
             for(auto it=t.begin();it!=t.end();it++)
            cout<<*it<<" ";
            cout<<endl;
        }
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