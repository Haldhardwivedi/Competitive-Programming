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

ll int x=1;

void solve() 
{
    string s,f;
    cin>>s;
    cin>>f;
    sort(s.begin(),s.end());
    map<char,int>m;
    ll int i;
    for(i=0;i<f.size();i++)
        m[f[i]]++;
    ll int count=0;
    for(i=0;i<s.size();i++)
    {
        if(m[s[i]]>0)
        continue;
        ll int left=0;
        ll int right=f.size()-1;
        while(left<right)
        {
            if(abs(left-right)<=1)
            break;
            ll int mid=(left+right)/2;
            if(f[mid]>s[i])
            {
                right=mid-1;
            }
            else 
            left=mid+1;
        }
        if(f[right]==122&&s[i]==97||f[right]=122&&s[i])
        ll int v1=abs(f[left]-s[i]);
        ll int v2=abs(f[right]-s[i]);
        count=count+min(v1,v2);
    }
    cout<<"Case #"<<x<<": "<<count<<endl;
    //cout<<count<<endl;
    x++;
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