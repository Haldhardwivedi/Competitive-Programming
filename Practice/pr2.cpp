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
    ll int s[n];
    ll int i;
    for(i=0;i<n;i++)
        cin>>s[i];
    if(n%2==0)
    cout<<"no"<<endl;
    else 
    {
        ll int mid=n/2;
        ll int left=n/2-1;
        ll int right=n/2+1;
        if(s[mid]!=mid+1)
        {
            cout<<"no"<<endl;
        }
        else 
        {
            int flag=0;
            int val=s[mid]-1;
            while(s[left]==s[right]&&s[left]==val&&left>=0&&right<n)
            {
                left--;
                right++;
                val--;
            }
            if(left==-1&&right==n)
            cout<<"yes"<<endl;
            else
            cout<<"no"<<endl;
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