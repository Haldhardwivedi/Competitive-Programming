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
    set<ll int>s1,s2,a1,a2;
    ll int i;
    s1.insert(a);
    s2.insert(b);
    map<ll int,ll int>m1,m2;
    for(i=1;i<=n;i++)
    {
        if(i!=a&&i>a)
        {
            s1.insert(i);
            m1[i]++;
        }
        else if(i!=b&&i<b)
        {
            s2.insert(b);
            m1[i]++;
        }
    }
    vector<ll int>v;

    for(auto it=s1.begin();it!=s1.end();it++)
    {
        if(m1[*it]==2)
        v.push_back(*it);
    }
    for(auto it=s1.begin();it!=s1.end();it++)
    {
        if(find(v.begin(),v.end(),*it)==v.end())
        {
            a1.insert(*it);
        }
    }
    for(auto it=s2.begin();it!=s2.end();it++)
    {
        if(find(v.begin(),v.end(),*it)==v.end())
        {
            a2.insert(*it);
        }
    }
    ll int val=n-a1.size()-a2.size();
    cout<<a1.size()<<" "<<a2.size()<<endl;
    if(n==v.size())
    {
        auto it=v.begin();
        while(a1.size()!=n/2&&it!=v.end());
        {
            a1.insert(*it);
            it++;
        }
        while(a2.size()!=n/2&&it!=v.end())
        {
            a2.insert(*it);
            it++;
        }
        for(auto it1=a1.begin();it1!=a1.end();it1++)
        {
            cout<<*it1<<" ";
        }
        for(auto it1=a2.begin();it1!=a2.end();it1++)
        {
            cout<<*it1<<" ";
        }
    }
    else
    cout<<-1<<endl;
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