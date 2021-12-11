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


int bs(int left,int right,int *a,int x)
{
    if(left>right)
    return(-1);
    int mid=left+right;
    mid=mid/2;
    if(a[mid]==x)
    {
        return(mid);
    }
    else if(a[mid]>x) 
    {
        right=mid-1;
        return(bs(left,right,a,x));
    }
    else 
    {
        left=mid+1;
        return(bs(left,right,a,x));
    }
}

void solve() 
{
    int a[6]={10,11,22,33,44,55};
    int n=6;
    cout<<bs(0,5,a,66)<<endl;
}


int main() 
{
    ll int t = 1;
    //sl(t);
    while(t--) 
    {
        solve();
    }
    return 0;
}