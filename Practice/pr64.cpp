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
    float x1,p1,x2,p2;
    cin>>x1>>p1>>x2>>p2;
    ll int d1=floor(log10(x1))+1;
    ll int d2=floor(log10(x2))+1;
    if(d1==d2)
    {
        if(p1==p2)
        {
            if(x1>x2)
            cout<<">"<<endl;
            else if(x1<x2)
            cout<<"<"<<endl;
            else if(x1==x2)
            cout<<"="<<endl;
        }
        else if(p1>p2)
        cout<<">"<<endl;
        else 
        cout<<"<"<<endl;
    }
    else 
    {
        if(d1>d2)
        {
            x1=x1/pow(10,d1-d2);
            p1=p1+d1-d2;
        }
        else 
        {
            x2=x2/pow(10,d2-d1);
            p2=p2+d2-d1;
        }
        if(p1>p2)
        cout<<">"<<endl;
        else if(p1<p2)
        cout<<"<"<<endl;
        else if(p1==p2)
        {
            if(x1>x2)
            cout<<">"<<endl;
            else if(x1<x2)
            cout<<"<"<<endl;
            else if(x1==x2)
            cout<<"="<<endl;
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