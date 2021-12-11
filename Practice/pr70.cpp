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
    ll int i;
    ll int count=0;
    for(i=0;i<n;i++)
    {
            if(i+2<n&&s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c')
            {
                count++;
            }
    }
    for(i=0;i<q;i++)
    {
        ll int pos;
        char ch;
        cin>>pos>>ch;
        pos--;
        ll int j;
        ll int x=0,y=0;
        for(j=max(0,pos-2);j<=min(n-1,pos+2);j++)
        {
            if(j+2>=n)
            {
                break;
            }
            if(s[j]=='a'&&s[j+1]=='b'&&s[j+2]=='c')
            {
                x++;
            }
        }
        //cout<<x<<" ";
        s[pos]=ch;
        for(j=max(0,pos-2);j<=min(n-1,pos+2);j++)
        {
            if(j+2>=n)
            {
                break;
            }
            if(s[j]=='a'&&s[j+1]=='b'&&s[j+2]=='c')
            {
                y++;
            }
        }
        //cout<<y<<endl;
        //cout<<x<<" "<<y<<endl;
        cout<<count-x+y<<endl;
        count=count-x+y;
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