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
    ll int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    ll int i,pos;
    ll int count=0;
    fo(i,n)
    {
        if(i+2<n&&s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c')
        {
            count++;
        }
    }
    char ch;
    ll int tt;
    for(tt=0;tt<q;tt++)
    {
        cin>>pos>>ch;
        pos--;
        ll int cnt=0;
        for(i=max(0,pos-2);i<= min(n, pos + 2);i++)
        {
            if(i+2<n&&s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c')
            {
                cnt++;
            }
        }
        s[pos]=ch;
        ll int ans=count-cnt;
        cnt=0;
        for(i=max(0,pos-2);i< min(n, pos + 2);i++)
        {
            if(i+2<n&&s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c')
            {
                cnt++;
            }
        }
        cout<<ans+cnt<<endl;
    }

}


int main() 
{

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll int t = 1;
    //sl(t);
    while(t--) 
    {
        solve();
    }
    return 0;
}