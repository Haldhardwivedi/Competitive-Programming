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
    ll int x,n;
    cin>>x>>n;
    ll int i;
    ll int pos=x;
    if(x%2==0)
    {
        x=x-1;
    }
    else 
    {
        x=x+1;
    }
    i=2;
    ll int val=1;
    while(pos!=x)
    {
        if(x%2==0)
        {
            x=x-i;
        }
        else 
        {
            x=x+i;
        }
        i++;
        val++;
    }
    if(n%val==0)
    cout<<x<<endl;
    else 
    {
        for(i=1;i<=n%val;i++)
        {
             if(x%2==0)
            {
                x=x-i;
            }
            else 
            {
                x=x+i;
            }
        }
        cout<<x<<endl;
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