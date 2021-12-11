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
    ll int a,b;
    cin>>a>>b;
    string s;
    cin>>s;
    if(a+b!=s.size())
    {
        cout<<-1<<endl;
    }
    else if(s.size()==1)
    {
        if(a==1)
        cout<<1<<endl;
        else
        cout<<0<<endl;
    }
    else 
    {
        ll int n=s.size();
        if(n%2!=0)
        {
            if(s[n/2]=='?'&&a%2!=0&&b%2==0)
            s[n/2]='0';
            else if(s[n/2]=='?'&&b%2==0&&a%2==1)
            s[n/2]='1';
            else 
            cout<<-1<<endl;
        }
        ll int l=0,r=n-1;
        ll int cnt=0;
        int flag=0;
        while(l<=r)
        {
            if(s[l]=='?'&&s[r]=='?')
            {
                if(a>=2)
                {
                    s[l]='0';
                    s[r]='0';
                    a=a-2;
                }
                else if(b>=2)
                {
                    s[l]='1';
                    s[r]='1';
                    b=b-2;
                }
                else 
                {
                    cout<<-1<<endl;
                    return;
                }
            }
            else if(s[l]=='?'&&s[r]!='?')
            {
                s[l]=s[r];
                if(s[r]=='0')
                    a=a-2;
                else if(s[r]=='1')
                    b=b-2;
            }
            else if(s[r]=='?'&&s[l]!='?') 
            {
                s[r]=s[l];
                if(s[l]=='0')
                    a=a-2;
                else if(s[l]=='1')
                    b=b-2;
            }
            else if(s[l]!=s[r])
            {
                flag=1;
                break;
            }
            else
            {
                if(s[l]=='0')
                a=a-2;
                else 
                b=b-2;
            }
            l++;
            r--;
        }
        if(a<0||b<0||flag==1)
        cout<<-1<<endl;
        else 
        {
            cout<<s<<endl;
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