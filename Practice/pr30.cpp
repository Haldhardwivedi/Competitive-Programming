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
    string s;
    cin>>s;
    ll int i;
    ll int n=s.size();
    ll int f=-1,g=-1;
    for(i=0;i<n;i++)
    {
        if(s[i]=='/'&&f==-1)
        f=i;
        else if(s[i]==92)
        g=i;
    }
    if(f==-1&&g==-1)
    cout<<-1<<endl;
    else if(g>f)
    {
        cout<<g<<" "<<f<<endl;
        ll int k;
        ll int count=0;
        for(k=f+1;k<=g-1;k++)
        {
            if(s[k]=='*')
            count++;
        }
        if(count==0)
        cout<<-1<<endl;
        else 
        cout<<count+2<<endl;
    }
}


int main() 
{
    ll int t = 1;
    //sl(t);
    while(t--) 
    {
        solve();
    }
    return 0;
}