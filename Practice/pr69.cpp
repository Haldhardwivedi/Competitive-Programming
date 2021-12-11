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


ll int calculate(ll int n1,ll int n2)
{
    ll int d1=log10(n1)+1;
    ll int d2=log10(n2)+2;
    // cout<<"d1 hai "<<d1<<endl;
    // cout<<"d2 hai "<<d2<<endl;
    if(d1==1||d2==1)
    {
        return(n1*n2);
    }
    else
    {
        ll int a,b,c,d;
        ll int n=(min(d1,d2)/2);
        ll int v1=pow(10,n/2);
        ll int v2=pow(10,n/2);
        a=n1/v1;
        b=n1%v1;
        c=n2/v2;
        d=n2%v2;
        cout<<a<<" "<<b<<endl;
        cout<<c<<" "<<d<<endl;
        ll int m1=calculate(a,c);
        ll int m2=calculate(b,d);
        ll int p1=calculate(a+b,c+d);
        ll int val=p1-m2-m1;
        ll int ans=pow(10,n)*m1+m2+pow(10,n/2)*p1;
        return(ans);
    }
}

void solve() 
{
    ll int a,b;
    cin>>a>>b;
    cout<<calculate(a,b)<<endl;
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