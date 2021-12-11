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

bool isprime(ll int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
  
    if (n % 2 == 0 || n % 3 == 0)
        return false;
  
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
  
    return true;
}

void solve() 
{
    ll int n;
    cin>>n;
    ll int a[n];
    ll int i;
    ll int sum=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(!isprime(sum))
    {
        cout<<n<<endl;
        for(i=1;i<=n;i++)
        cout<<i<<" ";
        cout<<endl;
    }
    else 
    {
        int flag=-1;
        for(i=0;i<n;i++)
        {
            if(!isprime(sum-a[i]))
            {
                flag=i+1;
                break;
            }
        }
        cout<<n-1<<endl;
        for(i=1;i<=n;i++)
        {
            if(i==flag)
            continue;
            cout<<i<<" ";
        }
        cout<<endl;
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