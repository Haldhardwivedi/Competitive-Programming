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
    ll int a[n];
    ll int i;
    for(i=0;i<n;i++)
    cin>>a[i];
    ll int start=0;
    ll int end=n-1;
    int flag=0;
    vector<ll int>v;
    while(start<=end)
    {
        //cout<<start<<" "<<end<<endl;
        if(a[start]!=a[end])
        {
            flag=1;
            v.push_back(a[start]);
            v.push_back(a[end]);
        }
        end--;
        start++;
    }
    if(flag==0)
    {
        cout<<"YES"<<endl;
    }
    else 
    {
        int ans=0;
        for(i=0;i<v.size();i++)
        {
            start=0;
            end=n-1;
            flag=0;
            while(start<=end)
            {
                if(a[start]!=a[end]&&a[start]==v[i]||a[end]==v[i])
                {
                   if(a[start]==v[i])
                   start++;
                   else 
                   end--;
                }
                else if(a[start]!=a[end]&&a[start]!=v[i]&&a[end]!=v[i])
                {
                    flag=1;
                    break;
                }
                else 
                {
                    end--;
                    start++;
                }
            }
            if(flag==0)
            {
                ans=1;
                break;
            }
        }
        if(ans==1)
        cout<<"YES"<<endl;
        else 
        cout<<"NO"<<endl;
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