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
    ll int arr[n];
    ll int i;
    for(i=0;i<n;i++)
    cin>>arr[i];
    vector<int>v1,v2;
    for(i=0;i<n;i=i+2)
    {
        v1.push_back(arr[i]);
        if(i+1<n)
        v2.push_back(arr[i+1]);
    }
    sort(v1.begin(),v1.end(),greater<int>());
    sort(v2.begin(),v2.end());
    ll int j=0;
    //ll int count=0;
    for(i=0;i<n;i=i+2)
    {
        arr[i]=v1[j];
        if(i+1<n)
        arr[i+1]=v2[j];
        j++;
    }
    ll int count=0;
    for(i=0;i<v1.size();i++)
    {
        for(j=i;j<v2.size();j++)
        {
            //cout<<v1[i]*v2[j]<<endl;
            count+=v1[i]*v2[j];
        }
    }
    for(i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    cout<<count<<endl;
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