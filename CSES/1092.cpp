/*
author :Haldhar Dwivedi
emial:haldhardwivedi@gmail.com
*/
#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}
int mpow(int base, int exp); 
void ipgraph(int n, int m);
void dfs(int u, int par);
 
const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================
 
vi g[N];
int a[N];
ll int n;
 
 
void solve() 
{
  sl(n);
  ll val;
  val=(n*(n+1))/2;
  vector <long long int > v1,v2;
  if(val%2==1)
  {
     cout<<"NO"<<endl;
     exit(0);
  }
  else
  {
      cout<<"YES"<<endl;
      if(n%2==0)
      {
        int turn=1;
        ll int start=1;
        ll int last =n;
        while(start<=last)
        {
           if(turn)
           {
               v1.push_back(start);
               v1.push_back(last);
               turn=0;
           }
           else
           {
               v2.push_back(start);
               v2.push_back(last);
               turn=1;
           }
           start++;
           last--;
        }
      }
      else
      {
          ll int rem=val/2;
          int vis[n]={0};
          for(ll i=n;i>=1;i--)
          {
              if(rem>i)
              {
                  v1.push_back(i);
                  vis[i]=1;
                  rem=rem-i;
              }
              else
              {
                  v1.push_back(rem);
                  vis[rem]=1;
                  break;
              }
          }
          for(ll i=n;i>=1;i--)
          {
              if(vis[i]==0)
                v2.push_back(i);
          }
      }
    cout<<v1.size()<<endl;
    for(ll i=0;i<v1.size();i++)
        cout<<v1[i]<<" ";
        cout<<endl;
    cout<<v2.size()<<endl;
    for(ll i=0;i<v2.size();i++)
        cout<<v2[i]<<" ";
        cout<<endl;
      
  }
}
 
int main() 
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
 
    int t = 1;
    //cin >> t;
    while(t--) {
      solve();
    }
 
    return 0;
}
 
int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}
 
void ipgraph(int n, int m){
    int i, u, v;
    while(m--){
        cin>>u>>v;
    u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
}
 
void dfs(int u, int par){
    for(int v:g[u]){
        if (v == par) continue;
        dfs(v, u);
    }
}