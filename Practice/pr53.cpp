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
    ll int k,x;
    cin>>k>>x;
    ll int sum=(k*(k+1))/2+(k*(k-1))/2;//checking if x is sufficient eniugh to spam succefully
    if(sum<x)
    {
        cout<<2*k-1<<endl;
    }
    else 
    {
        sum=(k*(k+1))/2;
        if(x<sum)
        {
            sum=0;
            ll int i=1;
            ll int p=-1+sqrt(1+8*x);
            cout<<p/2<<endl;
        }
        else 
        {
            sum=(k*(k+1))/2;
            x=x-sum;
            ll int p=2*k-1+sqrt(pow(1-2*k,2)-8*x);
            cout<<k+p/2<<endl;
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