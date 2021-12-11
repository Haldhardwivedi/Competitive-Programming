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
    ll int i,a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    if(n==1&&a[i]==0)
    cout<<0<<endl;
    else if(n==1&&a[i]!=0)
    cout<<-1<<endl;
    else  
    {
        ll int p=a[n-3];
        ll int q=a[n-2];
        ll int r=a[n-1];
        if(p==q)
        {
            if(r!=0)
            cout<<-1<<endl;
            else
            cout<<0<<endl;
            return;
        }
        ll int x=0;
        int flag=-1;
        while(1)
        {
            ll int v1=p+x;
            ll int v2=q+x;
            ll int v3=r+x;
            ll int val=v1^v2;
            if(val==v3)
            {
                flag=x;
                break;
            }
            x++;
        }
        cout<<flag<<endl;
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